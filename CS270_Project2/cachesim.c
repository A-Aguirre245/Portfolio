#include "cachesim.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef LOGBSIZE
/* Cache blocks are 16 bytes */
#define LOGBSIZE 4
#endif

typedef struct{
	int counter;
}LFU_counter;

cache_t *cache_create(int s, int E, int delay, cache_t *nextlevel){
	cache_t *newCache = (cache_t *)malloc(sizeof(cache_t));
	if(newCache == NULL){
		return NULL;
	}

	newCache->cache_sets = (cacheset_t *)malloc(sizeof(cacheset_t) * (1 << s));

	if(newCache->cache_sets == NULL){
		return NULL;
	}

	for(int i = 0; i < (1 << s); i++){
		newCache->cache_sets[i].lines = (cacheline_t *)malloc(sizeof(cacheline_t) * E);
		newCache->cache_sets[i].useinfo = (LFU_counter *)calloc(E, sizeof(LFU_counter));

		if(newCache->cache_sets[i].lines == NULL || newCache->cache_sets[i].useinfo == NULL){
			return NULL;
		}

		for(int j = 0; j < E; j++){
			newCache->cache_sets[i].lines[j].block = (uint8_t *)malloc(sizeof(uint8_t) * (1 << LOGBSIZE));
			newCache->cache_sets[i].lines[j].valid = 0;
			newCache->cache_sets[i].lines[j].dirty = 0;	
		}
	}

	newCache->cache_s = s;
	newCache->cache_E = E;
	newCache->cache_delay = delay;
	newCache->cache_next = nextlevel;

	return newCache;
}

int cache_access(cache_t *c, addr_t addr, void *value, int size, int iswrite){
	
	if(c == NULL){
		return mem_access(addr,value,size,iswrite);
	}

	int offsetBits = LOGBSIZE;	
	int offset = addr & ((1 << offsetBits) - 1);
	int indexBits = (addr >> LOGBSIZE) & ((1 << c->cache_s) - 1);
	addr_t tag = (addr >> (LOGBSIZE + c->cache_s));	

	cacheset_t *temp = &(c->cache_sets[indexBits]);	
       	LFU_counter *count = temp->useinfo; 	

	int delay = c->cache_delay;
		
		for(int i = 0; i < c->cache_E; i++){
			if(temp->lines[i].valid != 0 && tag == temp->lines[i].tag){
				count[i].counter++;
			
				if(iswrite != 0){
					if(temp->lines[i].dirty != 0){
						mem_access(addr, temp->lines[i].block, size, iswrite);
						temp->lines[i].dirty = 0;
					}
				
					memcpy(value, &(temp->lines[i].block[offset]), size);
					temp->lines[i].dirty = 1;
				}
				return delay;	
			}
		}

		int min_counter = INT_MAX;
		int victim = 0;
	
		for(int j = 0; j < c->cache_E; j++){
			if(count[j].counter < min_counter && temp->lines[j].valid == 0){
				min_counter = count[j].counter;
				victim = j;
			}
		}	
		

		if(temp->lines[victim].dirty != 0 && temp->lines[victim].valid != 0){
			if(c->cache_next == NULL){
				delay += mem_access((temp->lines[victim].tag << (LOGBSIZE + c->cache_s)) | (indexBits << LOGBSIZE), temp->lines[victim].block, 1 << LOGBSIZE, 1);
			}else{
				delay += cache_access(c->cache_next, (temp->lines[victim].tag << (LOGBSIZE + c->cache_s)) | (indexBits << LOGBSIZE), temp->lines[victim].block, 1 << LOGBSIZE, 1);
			}

			delay += cache_access(c->cache_next, addr, value, size, iswrite);

			for(int j = 0; j < c->cache_E; j++){
				if(temp->lines[j].valid != 0){
					count[j].counter = 0;
				}
			}
			return delay;
		}
		memcpy((&temp->lines[victim].block[offset]), value, size);
		delay += cache_access(c->cache_next, addr, value, size, iswrite);
		temp->lines[victim].tag = tag;
		temp->lines[victim].valid = 1;
		temp->lines[victim].dirty = iswrite;
		
		return delay;
}
void cache_flush(cache_t *c){
	if(c == NULL || c->cache_sets == NULL){
		return;
	}
	for(int i = 0; i < (1 << c->cache_s); i++){
                cacheset_t *temp = &(c->cache_sets[i]);
                for(int j = 0; j < c->cache_E; j++){
                        if(temp->lines != NULL && temp->lines[j].dirty != 0){
                                if(c->cache_next == NULL){
                                        mem_access(temp->lines[j].tag, temp->lines[j].block, (1 << LOGBSIZE), 1);
                                }else{
                                        cache_flush(c->cache_next);
				}
                                temp->lines[j].dirty = 0;
			}else{
                        	temp->lines[j].valid = 0;
                	}
        	}
	}	
}	

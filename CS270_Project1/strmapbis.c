//Written by: Andres Aguirre

#include <stdio.h> // for printf, ONLY IN strmap_dump
#include <string.h> // for strcmp
#include <stdlib.h> // for malloc/calloc
#include "strmapbis.h"

/* Create a new hashtab, initialized to empty. */
strmap_t *strmap_create(int numbuckets){
	//checks that numbuckets is within range
	if(numbuckets > MAX_BUCKETS){
		numbuckets = MAX_BUCKETS;
	}else if(numbuckets < MIN_BUCKETS){
		numbuckets = MIN_BUCKETS;
	}

	//allocated memory for the new strmap, gives it an initial size of 0,
	//and setting the nbuckets to the given numbuckets
	strmap_t *temp = (strmap_t *) malloc(sizeof(strmap_t));
	temp->strmap_buckets = (smel_t **) calloc(numbuckets,sizeof(smel_t*));

	temp->strmap_size = 0;
	temp->strmap_nbuckets = numbuckets;
	return temp;
}

/* if the load factor is more than LFSLOP away from the target,
 * allocate a new array to bring the load factor within 1/8 of
 * the given target (i.e., between 7/8*target and 9/8*target),
 * then re-hash everything into that array, free the old bucket
 * array, and make the map point to the new bucket array.  (The only
 * fields that change in the map are strmap_buckets and strmap_nbuckets.)
 * If the load factor is already within the target range,
 * the map is left unchanged. 
 */
void strmap_resize(strmap_t *m, double target){
	//find current load factor, and check if resizing is needed	
	double loadF = strmap_getloadfactor(m);
	if(loadF < (1 - LFSLOP)*target || loadF > (1 + LFSLOP)*target){
		int ntemp_buck = m->strmap_size / target;

		//check that the new bucket size is within range
		if(ntemp_buck > MAX_BUCKETS){
			ntemp_buck = MAX_BUCKETS;
		}else if(ntemp_buck < MIN_BUCKETS){
			ntemp_buck = MIN_BUCKETS;
		}

		//allocating mem for new array
		smel_t** temp_bucks = calloc(ntemp_buck,sizeof(smel_t*));

		//rehash elements to the same spot they were at
		for(int i = 0; i < m->strmap_nbuckets; i++){
			smel_t* current = m->strmap_buckets[i];
			while(current){
		  		smel_t* next = current->sme_next;
				
				int keySize = strlen(current->sme_key);
				unsigned long hashKey = (10139 * keySize * 3);
				for(int j = 0; j < keySize; j++){
					hashKey = (hashKey ^ current->sme_key[j]);
				}
				hashKey = hashKey % (ntemp_buck);

				current->sme_next = temp_bucks[hashKey];
				temp_bucks[hashKey] = current;
				current = next;
			}
		}
		
		//free old array, and make new one point to the resized array
		free(m->strmap_buckets);
		m->strmap_buckets = temp_bucks;
		m->strmap_nbuckets = ntemp_buck;
	}
}

/* Insert an element with the given key and value.
 *  Return the previous value associated with that key, or null if none.
 */
void *strmap_put(strmap_t *m, char *key, void *value){

	//hash function to give keys an index
	int keySize = strlen(key);
	unsigned long hashKey = (10139 * keySize * 3);
	for(int i = 0; i < keySize; i++){
		hashKey = (hashKey ^ key[i]);
	}
	hashKey = hashKey % (m->strmap_nbuckets);

	smel_t* current = m->strmap_buckets[hashKey];
	smel_t* prev = NULL;
	int rv; 

	while(current && (rv = strcmp(key,current->sme_key)) != 0){
		prev = current;
		current = current->sme_next;
	}

        //this returns the value already associated at the given key, and then replaces it
	if(current && rv == 0){
		void *temp = current->sme_value;
                current->sme_value = value;
		return temp;
	}else{
		//this allocates memory for the new key not found
		smel_t *newe = (smel_t *) malloc(sizeof(smel_t));
		newe->sme_key = strdup(key);
		newe->sme_value = value;
		newe->sme_next = current;
        
		//adds the key at the start
		if(prev == NULL){
			m->strmap_buckets[hashKey] = newe;
		//adds the key inbetween two values
		}else{
			prev->sme_next = newe;
		}
	}	
	m->strmap_size++;
	return NULL;
}

/* return the value associated with the given key, or null if none */
void *strmap_get(strmap_t *m, char *key){
	
	int keySize = strlen(key);
	unsigned long hashKey = (10139 * keySize * 3);
	for(int i = 0; i < keySize; i++){
		hashKey = (hashKey ^ key[i]);
	}
	hashKey = hashKey % (m->strmap_nbuckets);

	smel_t* current = m->strmap_buckets[hashKey];
	int rv;

	while(current && (rv = strcmp(key,current->sme_key)) != 0){
                current = current->sme_next;
	}
	
	//if the key is found, the value is returned
	if(current && rv == 0){
		return current->sme_value;

	//null is returned if the key is not found
	}else{
		return NULL;
	}
}

/* remove the element with the given key and return its value.
   Return null if the hashtab contains no element with the given key */
void *strmap_remove(strmap_t *m, char *key){
	//hash fucntion
	int keySize = strlen(key);
	unsigned long hashKey = (10139 * keySize * 3);
	for(int i = 0; i < keySize; i++){
		hashKey = (hashKey ^ key[i]);
	}
	hashKey = hashKey % (m->strmap_nbuckets);


	smel_t* current = m->strmap_buckets[hashKey];
	smel_t* prev = NULL;
	int rv;

	while(current && (rv = strcmp(key,current->sme_key)) != 0){
		prev = current;
		current = current->sme_next;
	}
	
	//removes key and value from the linked list, and returns the value that was there
	if(current && rv == 0){
		void *temp = current->sme_value;
		if(prev == NULL){
			m->strmap_buckets[hashKey] = current->sme_next;	
		}else{
			prev->sme_next = current->sme_next;
		}
		m->strmap_size--;
		return temp;

	//if key was not found, null is returned
	}else{
		return NULL;
	}
}

/* return the # of elements in the hashtab */
int strmap_getsize(strmap_t *m){
	return m->strmap_size;
}

/* return the # of buckets in the hashtab */
int strmap_getnbuckets(strmap_t *m){
	return m->strmap_nbuckets;
}

/* print out the contents of each bucket */
void strmap_dump(strmap_t *m){
	printf("total elements = %d. \n", m->strmap_size); 
		
	for(int i = 0; i < m->strmap_nbuckets; i++){
		smel_t* current = m->strmap_buckets[i];
		if(current != NULL){
		        printf("bucket %d: \n", i);
			while(current != NULL){
				printf("  %s->%p \n", current->sme_key, current->sme_value);
				current = current->sme_next;
			}
		}
	}
}

/* return the current load factor of the map  */
double strmap_getloadfactor(strmap_t *m){
	double result = (double)(m->strmap_size) / (double)(m->strmap_nbuckets);
	return result;
}

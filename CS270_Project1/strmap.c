#include "strmap.h"

/* Create a new hashtab, initialized to empty. */
strmap_t *strmap_create(int numbuckets){

	//checks that numbuckets is within range
	if(numbuckets > MAX_BUCKETS){
		numbuckets = MAX_BUCKETS;
	}else if(numbuckets < MIN_BUCKETS){
		numbuckets = MIN_BUCKETS;
	}

	//allocated memory for the new strmap, gives it an initial size of 0, and setting the nbuckets to the given numbuckets
	strmap_t *temp = (strmap_t *) malloc(sizeof(strmap_t));
	temp->strmap_buckets = (smel_t **) calloc(numbuckets,sizeof(smel_t*));

	temp->strmap_size = 0;
	temp->strmap_nbuckets = numbuckets;
	return temp;
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
	smel_t** prev = &m->strmap_buckets[hashKey];
	int rv;

	while(current && (rv = strcmp(key,current->sme_key)) < 0){
		prev = &current->sme_next;
		current = current->sme_next;
	}

        //this returns the value already associated at the given key, and then replaces it
	if(current && rv == 0){
		void *temp = current->sme_value;
                current->sme_value = value;
		return temp;
	}
	

	//this allocates memory for the new key not found
	smel_t *newe = (smel_t *) malloc(sizeof(smel_t));
	newe->sme_key = key;
	newe->sme_value = value;
        
	//adds the key inbetween two values
	if(!current || rv > 0){
		newe->sme_next = current;
		*prev = newe;
	//adds the key at the start
	}else{
		newe->sme_next = current;
		*prev = m->strmap_buckets[0];
		
	} 
	m->strmap_size++;
	return NULL;

}
/* return the value associated with the given key, or null if none */
void *strmap_get(strmap_t *m, char *key){

	smel_t* current = m->strmap_buckets[0];
	int rv;

	while(current && (rv = strcmp(key,current->sme_key)) < 0){
		current = current->sme_next;
	}
	
	//if the key is found, the value is returned
	if(current && rv == 0){
		return current->sme_value;

	//null is returned if the key is not found
	}else{
		return NULL;
	}

	return NULL;

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
	smel_t** prev = &m->strmap_buckets[hashKey];
	int rv;
	m->strmap_size--;

	while(current && (rv = strcmp(key,current->sme_key)) < 0){
		prev = &current->sme_next;
		current = current->sme_next;
	}
	
	//removes key and value from the linked list, and returns the value that was there
	if(current && rv == 0){
		void *temp = current->sme_value;
		*prev = current->sme_next;
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

	printf("total elements = %d. \n",m->strmap_size); 
		
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

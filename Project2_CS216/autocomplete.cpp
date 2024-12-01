/* File: autocomplete.cpp
 * Course: CS216-001
 * Project: Project 2
 * Purpose: the implementation of member functions for the class named Autocomplete.
 *
 */
#include <iostream>
#include "autocomplete.h"

// default constructor
Autocomplete::Autocomplete()
{
    // You can leave it blank
    // since the private data member terms has been initialized through default constructor of SortingList class 
}


// inserts the newterm to the sequence
// note that a SortingList<Term> object, named terms
//          represents the sequence
void Autocomplete::insert(Term newterm)
{
	terms.insert(newterm);
}


// sort all the terms by query in the lexicographical order  
void Autocomplete::sort()
{
	terms.std_sort();		
}

// binary search helper function
// as private function
// since it serves binary_search member function only
int Autocomplete::binary_searchHelper(SortingList<Term> terms, string key, int left_index, int right_index)
{
    if(right_index < left_index)
    {
        int KEY_NOT_FOUND = -1;
        return KEY_NOT_FOUND;
    }
    else
    {
        Term keyterm(key, 0);
        int r = key.length();
        int middle = (left_index + right_index) / 2;
        if(Term::compareByPrefix(keyterm,terms[middle],r) > 0)
        {
            return binary_searchHelper(terms, key, left_index, middle - 1);

        }
        else if(Term::compareByPrefix(keyterm,terms[middle],r)  < 0)
        {
            return binary_searchHelper(terms, key, middle + 1, right_index);
        }
        else
        {
            return middle;
        }
    }
}

// return the index number of the term whose query 
// prefix-matches the given prefix, using binary search algorithm
// Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete::binary_search(string prefix)
{
	return binary_searchHelper(terms, prefix, 0, terms.size() - 1);
}

// first: the index of the first query whose prefix matches
//          the search key, or -1 if no such key
// last: the index of the last query whose prefix matches 
//         the search key, or -1 if no such key
// key: the given prefix to match
// hints: you can call binary_search() first to find one matched index number,
//        say hit, then look up and down from hit, to find first and last respectively
void Autocomplete::search(string key, int& firstIndex, int& lastIndex, int length)
{
	int hit = binary_search(key);
	if(hit == -1){
		firstIndex = -1;
		lastIndex = -1;
		return;
	}else{	
	int right = hit;
	int left = 0;
	
	while(right >= left){
		int middle = (left + right)/2;
		if(Term::compareByPrefix(terms[middle],Term(key, 0), key.length()) == 0){
			firstIndex = middle;
			right = middle - 1;
		}else{
			left = middle + 1;
		}	
	}	
	right = terms.size() - 1;	
	left = hit;
	
	while(left <= right){
		int middle = (left + right)/2;
		if(Term::compareByPrefix(terms[middle],Term(key, 0), key.length())  == 0){
			lastIndex = middle;
			left = middle + 1;
		}else{
			right = middle - 1; 
		}
	}
	}
}

// returns all terms that start with the given prefix, in descending order of weight
SortingList<Term> Autocomplete::allMatches(string prefix, int length)
{
	int first;
	int last;
	search(prefix, first, last, length);
	SortingList<Term> termsList;
	if(first == -1){
		return termsList;
	}else{
		for(int i = first; i <= last; i++){
			termsList.insert(terms[i]);
		}
		termsList.merge_sort(Term::compareByWeight);	
	}
	SortingList<Term> lastCount;
	if(length > termsList.size()){
		return termsList;
	}else{
		for(int i = 0; i < length; i++){
			lastCount.insert(termsList[i]);
		}
		return lastCount;
	}
}

void Autocomplete::print()
{
	terms.print();
}

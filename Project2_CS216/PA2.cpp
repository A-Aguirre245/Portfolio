/*
 * Course: CS216-001
 * Project: Lab 9 (as second part of Project 2)
 * Purpose: repeatedly ask the user to type prefix to match
 *          and generate all the prefix-matched terms 
 *          then display the prefix-matched terms in descending order by weight.
 * Author: Andres Aguirre
 */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "term.h"
#include "SortingList.h"
#include "autocomplete.h"

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 2;
    
    //check to see if file and number are given
    if(argc != ARGUMENTS+1){
	    cout << "Warning: need exactly 2 command line arguments." << endl;
            cout << "Usage: " << argv[0] << " <filename> number" << endl;
            return 1;
    }    
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Warning: cannot open the file named " << argv[1] << "!" << endl;
        return 1;
    }

    //sets numK to the numebr of matchedterms wanted
    string temp = argv[2];
    int numK = stoi(temp);  

    // check to see if user entered valid k number
    if(numK <= 0){
	cout << "Warning: the number of matching terms needs to be a positive number!" << endl;
	return 1;
    }    
    
    // read in the terms from the input file
    // line by line and store into Autocomplete object
    Autocomplete autocomplete;
    long weight;
    string query;
    
    while (!infile.eof())
    {
        infile >> weight >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            autocomplete.insert(newterm);
        }    
    }
    
    autocomplete.sort();   
    string input;
    string prefix;
    cout << "Please input the search query (type \"exit\" to quit): " << endl;
    getline(cin, input);
    prefix = input;
    while (prefix != "exit")
    {
        // measure the time spent for searching one prefix-matched term
        SortingList<Term> matchedTerms = autocomplete.allMatches(prefix, numK);        
        if (matchedTerms.size() == 0)
        {    
            cout << "No matched query!" << endl;
        }
        else
        {
            matchedTerms.print();
        }
	cout << "Please input the search query (type \"exit\" to quit): " << endl;
	getline(cin, input);
	prefix = input;
    }    
    return 0;
} 

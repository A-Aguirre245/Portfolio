/* File: Sort.h
 * Course: CS315
 * Project: Project 1 Sorting
 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#ifndef SORT_H
#define	SORT_H

using namespace std;

const int maxSmall = 166;
const int maxMed = 432;
const int maxLarge = 800;

int insertionSort(int* a, int size);

void quickSort(int* a, int p, int r, int &count);

int partition(int* a, int p, int r, int &count);

void mergeSort(int* a, int p, int r, int &count);

int daMerge(int* a, int p, int q, int r);

void convertIn(string s, int* array);

void printSort(int* a, int size);


#endif
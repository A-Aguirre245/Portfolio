#ifndef LCS_H
#define	LCS_H

#include <string>

using namespace std;

int lcs_length(string x, string y, string **b, int **c);

void print_LCS(string **b, string x, int i, int j);


#endif
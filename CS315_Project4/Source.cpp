#include "LCS.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream dnaFile("dna.txt");
	string dna1, dna2;
	getline(dnaFile, dna1);
	getline(dnaFile, dna2);

	int m = dna1.length() + 1;
	int n = dna2.length() + 1;

	int **c = new int*[m];
	for (int i = 0; i < m; i++) {
		c[i] = new int[n];
	}

	string** b = new string*[m];
	for (int i = 0; i < m; i++) {
		b[i] = new string[n];
	}
	cout << "Length of LCS: " << lcs_length(dna1, dna2, b, c) << endl;
	cout << "LCS of two DNA strings: ";
	print_LCS(b, dna1, m - 1, n - 1);

	for (int i = 0; i < m; ++i) {
		delete[] b[i];
	}
	delete[] b;

	for (int i = 0; i < m; ++i) {
		delete[] c[i];
	}
	delete[] c;
}
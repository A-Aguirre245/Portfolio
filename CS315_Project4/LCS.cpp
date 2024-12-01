#include "LCS.h"
#include <iostream>

int lcs_length(string x, string y, string **b, int **c)
{
	int m = x.length() + 1;
	int n = y.length() + 1;

	for (int i = 0; i < m; i++) {
		c[i][0] = 0;
	}

	for (int j = 0; j < n; j++) {
		c[0][j] = 0;
	}
	
	for (int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++){
				if (x.substr(i - 1, 1) == y.substr(j - 1, 1)) {
					c[i][j] = c[i - 1][j - 1] + 1;
					b[i][j] = "d";
				}else if (c[i - 1][j] >= c[i][j - 1]) {
					c[i][j] = c[i - 1][j];
					b[i][j] = "u";
				}else {
					c[i][j] = c[i][j - 1];
					b[i][j] = "l";
				}
		}
	}

	return c[m - 1][n - 1];
}

void print_LCS(string **b, string x, int i, int j)
{
	if (i == 0 || j == 0) {
		return;
	}

	if (b[i][j] == "d") {
		print_LCS(b, x, i - 1, j - 1);
		cout << x.substr(i - 1, 1);
	}else if (b[i][j] == "u") {
		print_LCS(b, x, i - 1, j);
	}else{
		print_LCS(b, x, i, j - 1);
	}
}

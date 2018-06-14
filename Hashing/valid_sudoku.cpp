#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<string> &b, int i, int j, char v) {
	for(int r = i, c = 0; c < 9; ++c) {
		if(!(r == i && c == j) && b[r][c] == v) {
			return false;
		}
	}

	for(int r = 0, c = j; r < 9; ++r) {
		if(!(r == i && c == j) && b[r][c] == v) {
			return false;
		}
	}

	int bi = (i / 3) * 3;
	int bj = (j / 3) * 3;
	for(int r = bi; r < bi + 3; ++r) {
		for(int c = bj; c < bj + 3; ++c) {
			if(!(r == i && c == j) && b[r][c] == v) {
				return false;
			}
		}
	}

	return true;
}

int isValidSudoku(const vector<string> &A) {
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			if(A[i][j] != '.' && !is_safe(A, i, j, A[i][j])) {
				return 0;
			}
		}
	}
	
	return 1;
}
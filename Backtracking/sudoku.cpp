#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> ans;

bool is_safe(vector<vector<char>> &b, int i, int j, char v) {
	for(int r = i, c = 0; c < 9; ++c) {
		if(b[r][c] == v) {
			return false;
		}
	}

	for(int r = 0, c = j; r < 9; ++r) {
		if(b[r][c] == v) {
			return false;
		}
	}

	int bi = (i / 3) * 3;
	int bj = (j / 3) * 3;
	for(int r = bi; r < bi + 3; ++r) {
		for(int c = bj; c < bj + 3; ++c) {
			if(b[r][c] == v) {
				return false;
			}
		}
	}

	return true;
}

void util(vector<vector<char>> &b, int i, int j) {
	if(i >= 9) {
		ans = b;
		return;
	}

	int ni, nj;
	if(j + 1 < 9) {
		ni = i;
		nj = j + 1;
	}
	else {
		ni = i + 1;
		nj = 0;
	}

	if(b[i][j] != '.') {
		util(b, ni, nj);
	}
	else {
		for(int v =  '1'; v <= '9'; ++v) {
			if(is_safe(b, i, j, v)) {
				b[i][j] = v;
				util(b, ni, nj);
				b[i][j] = '.';
			}
		}
	}
}

void solveSudoku(vector<vector<char>> &A) {
    util(A, 0, 0);
    A = ans;
}

int main(void) {
	vector<string> b(9);
	for(int i = 0; i < 9; ++i) {
		cin >> b[i];
	}

	vector<vector<char>> board(9, vector<char>(9, '.'));
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			board[i][j] = b[i][j];
		}
	}

	solveSudoku(board);

	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
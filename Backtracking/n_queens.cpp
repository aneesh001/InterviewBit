#include <bits/stdc++.h>
using namespace std;

bool can_place(const vector<string> &current, int i, int j, int A) {
	for(int p = i - 1; p >= 0; --p) {
		if(current[p][j] == 'Q') {
			return false;
		}
	}

	for(int r = i - 1, c = j - 1; r >= 0 && c >= 0; --r, --c) {
		if(current[r][c] == 'Q') {
			return false;
		}
	}

	for(int r = i - 1, c = j + 1; r >= 0 && c < A; --r, ++c) {
		if(current[r][c] == 'Q') {
			return false;
		}
	}

	return true;
}

void util(vector<string> &current, vector<vector<string>> &ans, int i, int A) {
	if(i >= A) {
		ans.push_back(current);
		return;
	}

	for(int j = 0; j < A; ++j) {
		if(can_place(current, i, j, A)) {
			current[i][j] = 'Q';
			util(current, ans, i + 1, A);
			current[i][j] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int A) {
    string s(A, '.');
    vector<string> current(A, s);
    vector<vector<string>> ans;

    util(current, ans, 0, A);

    return ans;
}

int main(void) {
	int n;
	cin >> n;

	cout << "Total number of solution: " << solveNQueens(n).size() << endl << endl;
	for(auto &v: solveNQueens(n)) {
		for(auto &s: v) {
			cout << s << endl;
		}
		cout << "solution end!\n" << endl;
	}

	return 0;
}
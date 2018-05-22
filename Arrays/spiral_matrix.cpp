#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

vector<vector<int>> generateMatrix(int A) {
	int val = 1;
	vector<vector<int>> ans(A, vector<int>(A, 0));

	int k = 0, l = 0, i;
	int m = A, n = A;

	while(k < m && l < n) {
		for(i = l; i < n; ++i) {
			ans[k][i] = val;
			++val;
		}
		++k;

		for(i = k; i < m; ++i) {
			ans[i][n - 1] = val;
			++val;
		}
		--n;

		if(k < m) {
			for(i = n - 1; i >= l; --i) {
				ans[m - 1][i] = val;
				++val;
			}
			--m;
		}

		if(l < n) {
			for(i = m - 1; i >= k; --i) {
				ans[i][l] = val;
				++val;
			}
			++l;
		}
	}

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	for(auto &v: generateMatrix(n)) {
		for(int i: v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
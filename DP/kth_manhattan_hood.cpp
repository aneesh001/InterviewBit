#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

vector<vector<int>> solve(int A, vector<vector<int>> &B) {
	int n = B.size();
	int m = B[0].size();

	vector<vector<int>> ans(n, vector<int>(m, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			ans[i][j] = B[i][j];
		}
	}

	for(int k = 1; k <= A; ++k) {
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				dp[i][j] = ans[i][j];
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int ni = i + 1, nj = j;
				if(valid(ni, nj, n, m) && dp[i][j] < ans[ni][nj]) {
					dp[i][j] = ans[ni][nj];
				}

				ni = i - 1, nj = j;
				if(valid(ni, nj, n, m) && dp[i][j] < ans[ni][nj]) {
					dp[i][j] = ans[ni][nj];
				}

				ni = i, nj = j + 1;
				if(valid(ni, nj, n, m) && dp[i][j] < ans[ni][nj]) {
					dp[i][j] = ans[ni][nj];
				}

				ni = i, nj = j - 1;
				if(valid(ni, nj, n, m) && dp[i][j] < ans[ni][nj]) {
					dp[i][j] = ans[ni][nj];
				}
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				ans[i][j] = dp[i][j];
			}
		}
	}

	return ans;
}

int main(void) {
	int k;
	cin >> k;

	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	for(auto &v: solve(k, grid)) {
		for(int i: v) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
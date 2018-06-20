#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A) {
	if(A.size() == 0) return 0;
	int n = A.size();
	int m = A[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	if(A[0][0] != 1) dp[0][0] = 1;
	for(int i = 1; i < n; ++i) {
		if(A[i][0] != 1) dp[i][0] += dp[i - 1][0];
	}
	for(int i = 1; i < m; ++i) {
		if(A[0][i] != 1) dp[0][i] += dp[0][i - 1];
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < m; ++j) {
			if(A[i][j] != 1) {
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[n - 1][m - 1];
}

int main(void) {
	return 0;
}
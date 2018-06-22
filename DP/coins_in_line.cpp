#include <bits/stdc++.h>
using namespace std;

int maxcoin(vector<int> &A) {
	if(A.size() == 0) return 0;

	int n = A.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int len = 0; len < n; ++len) {
		for(int i = 0; i < n - len; ++i) {
			int j = i + len;

			if(len == 0) {
				dp[i][j] = A[i];
			}
			else if(len == 1) {
				dp[i][j] = max(A[i], A[j]);
			}
			else {
				int a = (i + 2 <= j) ? dp[i + 2][j] : 0;
				int b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
				int c = (i <= j - 2) ? dp[i][j - 2] : 0;

				dp[i][j] = max(A[i] + min(a, b), A[j] + min(b, c));
			}
		}
	}

	return dp[0][n - 1];
}

int main(void) {
	return 0;
}
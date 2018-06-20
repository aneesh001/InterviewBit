#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solve(int A, int B) {
	vector<vector<int>> dp(A + 1, vector<int>(B + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= A; ++i) {
		dp[i][0] = 0;
	}
	dp[1][0] = 1;
	for(int i = 1; i <= B; ++i) {
		dp[0][i] = 0;
	}
	for(int i = 1; i <= A; ++i) {
		for(int j = 1; j <= B; ++j) {
			for(int d = (i == 1) ? 1 : 0; d <= 9; ++d) {
				if(j - d > 0 || (j - d == 0 && i - 1 == 0)) {
					dp[i][j] = (dp[i][j] + dp[i][j - d]) % MOD;
				}
			}
		}
	}

	return dp[A][B];
}

int main(void) {
	return 0;
}
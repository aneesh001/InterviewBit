#include <bits/stdc++.h>
using namespace std;

int minDistance(string A, string B) {
	int n = A.size();
    int m = B.size();
    while(n - 1 >= 0 && !isalpha(A[n - 1])) --n;
    while(m - 1 >= 0 && !isalpha(B[m - 1])) --m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
	return dp[n][m];
}

int main(void) {
	return 0;
}
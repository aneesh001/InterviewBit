#include <bits/stdc++.h>
using namespace std;

int isInterleave(string A, string B, string C) {
    int n = A.size();
    int m = B.size();
    int p = C.size();

    if(n + m != p) return 0;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] && A[i - 1] == C[i - 1];
    }
    for(int i = 1; i <= m; ++i) {
        dp[0][i] = dp[0][i - 1] && B[i - 1] == C[i - 1];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int k = i + j - 1;

            if(C[k] == A[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            if(C[k] == B[j - 1]) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;

    cout << isInterleave(a, b, c) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] += dp[i - 1][j];
        }
    }

    return dp[n][m];
}

int main(void) {
    string a, b;
    cin >> a >> b;

    cout << numDistinct(a, b) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int isMatch(const string text, const string pat) {
    int n = pat.size();
    int m = text.size();

    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] && pat[i - 1] == '*';
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(pat[i - 1] == '?' || pat[i - 1] == text[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(pat[i - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main(void) {
    return 0;
}

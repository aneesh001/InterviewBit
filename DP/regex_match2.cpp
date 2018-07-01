#include <bits/stdc++.h>
using namespace std;

int isMatch(const string text, const string pat) {
    int n = pat.size();
    int m = text.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 2][0] && pat[i - 1] == '*';
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(pat[i - 1] == '.' || pat[i - 1] == text[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(pat[i - 1] == '*' && pat[i - 2] == '.') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 2][j];
            }
            else if(pat[i - 1] == '*' && pat[i - 2] == text[j - 1]) {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 2][j];
            }
            else if(pat[i - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i - 2][j];
            }
        }
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

int main(void) {
    string t, p;
    cin >> t >> p;

    cout << isMatch(t, p) << endl;
    return 0;
}

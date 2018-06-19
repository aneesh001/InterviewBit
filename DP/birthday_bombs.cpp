#include <bits/stdc++.h>
using namespace std;

// Takes too much memory. Implement greedy solution.
vector<int> solve(int A, vector<int> &B) {
	reverse(B.begin(), B.end());
    int n = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(A + 1, 0));

    for(int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= A; ++i) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= A; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(B[i - 1] <= j && 1 + dp[i][j - B[i - 1]] >= dp[i - 1][j]) {
                dp[i][j] = 1 + dp[i][j - B[i - 1]];
            }
        }
    }

    vector<int> ans;
    int i = n, j = A;
    while(i > 0 && j > 0) {
        if(j - B[i - 1] >= 0 && dp[i][j] == 1 + dp[i][j - B[i - 1]]) {
            ans.push_back(n - i);
            j -= B[i - 1];
        }
        else {
            --i;
        }
    }
    return ans;
}

int main(void) {
	return 0;
}
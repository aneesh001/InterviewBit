#include <bits/stdc++.h>
using namespace std;

int numDecodings(string A) {
	if(A.size() == 0) {
        return 0;
    }

    int n = A.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        int j = i - 1;
        if(stoi(A.substr(j, 1)) > 0) {
            dp[i] += dp[i - 1];
        }
        if(j - 1 >= 0 && A[j - 1] != '0' && stoi(A.substr(j - 1, 2)) > 0 && 
            stoi(A.substr(j - 1, 2)) <= 26) {
            
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
}

int main(void) {
	return 0;
}
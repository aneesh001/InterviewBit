#include <bits/stdc++.h>
using namespace std;

struct node {
	unordered_map<int, int> mp;
	int m;

	node(): m(1) { };
};

int solve(const vector<int> &A) {
	int n = A.size();
    if(n == 0) return 0;

    node dp[n];
    for(int i = 1; i < n; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            int d = A[i] - A[j];
            auto it = dp[j].mp.find(d);

            if(it == dp[j].mp.end()) {
                dp[i].mp[d] = max(2, dp[i].mp[d]);
                dp[i].m = max(dp[i].m, dp[i].mp[d]);
            }
            else {
                dp[i].mp[d] = max(dp[j].mp[d] + 1, dp[i].mp[d]);
                dp[i].m = max(dp[i].m, dp[i].mp[d]);
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, dp[i].m);
    }

    return ans;
}

int main(void) {
	return 0;
}
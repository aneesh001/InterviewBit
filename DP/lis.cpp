#include <bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
	int n = A.size();
	vector<int> dp(n, 1);
	for(int i = 1; i < n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(A[i] > A[j]) dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main(void) {
	return 0;
}
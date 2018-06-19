#include <bits/stdc++.h>
using namespace std;

int climbStairs(int A) {
	vector<int> dp(A + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= A; ++i) {
		if(i - 1 >= 0) {
			dp[i] += dp[i - 1];
		}
		if(i - 2 >= 0) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[A];
}

int main(void) {
	return 0;
}
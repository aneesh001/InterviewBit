#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int chordCnt(int A) {
	vector<long long> dp(A + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= A; ++i) {
		long long s = 0;
		for(int j = 0; j <= i - 1; ++j) {
			s = (s + (dp[j] * dp[i - 1 - j]) % mod) % mod;
		}
		dp[i] = s;
	}
	return dp[A];
}

int main(void) {
	return 0;
}
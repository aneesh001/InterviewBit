#include <bits/stdc++.h>
using namespace std;

int longestSubsequenceLength(const vector<int> &A) {
	int n = A.size();
	vector<int> dp1(n, 1);
	vector<int> dp2(n, 1);
	for(int i = 1; i < n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(A[i] > A[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
	for(int i = n - 2; i >= 0; --i) {
		for(int j = i + 1; j < n; ++j) {
			if(A[i] > A[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, dp1[i]);
		ans = max(ans, dp2[i]);
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	return ans;
}

int main(void) {
	return 0;
}
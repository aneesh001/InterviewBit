#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A) {
	int n = A.size();

	if(n == 0) return 0;

	vector<int> left(n, INT_MIN);
	left[0] = 0;
	int minm = A[0];
	for(int i = 1; i < n; ++i) {
		minm = min(minm, A[i]);
		left[i] = max(left[i - 1], A[i] - minm);
	}

	vector<int> right(n, INT_MIN);
	right[n - 1] = 0;
	int maxm = A[n - 1];
	for(int i = n - 2; i >= 0; --i) {
		maxm = max(maxm, A[i]);
		right[i] = max(right[i + 1], maxm - A[i]);
	}

	int ans = INT_MIN;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, left[i] + right[i]);
	}

	return ans;
}

int main(void) {
	return 0;
}
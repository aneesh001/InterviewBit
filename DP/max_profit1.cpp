#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A) {
	int n = A.size();

	if(n == 0) return 0;

	int ans = 0;
	int minimum = A[0];
	for(int i = 1; i < n; ++i) {
		minimum = min(minimum, A[i]);
		ans = max(ans, A[i] - minimum);
	}

	return ans;
}

int main(void) {
	return 0;
}
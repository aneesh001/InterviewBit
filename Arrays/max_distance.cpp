#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
	int n = A.size();
	vector<int> left_min(n), right_max(n);
	
	int minm = A[0];
	left_min[0] = minm;
	for(int i = 1; i < A.size(); ++i) {
		minm = min(minm, A[i]);
		left_min[i] = minm;
	}

	int maxm = A[n - 1];
	right_max[n - 1] = maxm;
	for(int i = n - 2; i >= 0; --i) {
		maxm = max(maxm, A[i]);
		right_max[i] = maxm;
	}

	int i = 0, j = 0;
	int ans = -1;

	while(i < n && j < n) {
		if(left_min[i] > right_max[j]) {
			++i;
		}
		else {
			ans = max(ans, j - i);
			++j;
		}
	}

	return ans;
}

int main(void) {

}
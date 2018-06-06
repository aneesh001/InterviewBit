#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	int i = 0, j = 0, k = 0;

	int ans = INT_MAX;

	while(i < A.size() && j < B.size() && k < C.size()) {
		int minm = min(A[i], min(B[j], C[k]));
		int maxm = max(A[i], max(B[j], C[k]));
		ans = min(ans, abs(maxm - minm));

		if(minm == A[i]) {
			++i;
		}
		else if(minm == B[j]) {
			++j;
		}
		else {
			++k;
		}
	}

	return ans;
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &A) {
	int n = A.size();
	vector<int> min_jumps(n, INT_MAX);
	int max_reachable = 0;
	min_jumps[0] = 0;
	
	for(int i = 0; i < n; ++i) {
		if(i > max_reachable) return -1;

		for(int j = max_reachable; j <= i + A[i] && j < n; ++j) {
			min_jumps[j] = min(min_jumps[j], 1 + min_jumps[i]);
		}

		max_reachable = max(max_reachable, i + A[i]);
	}

	return min_jumps[n - 1];
}

int main(void) {
	return 0;
}
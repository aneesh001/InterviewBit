#include <bits/stdc++.h>
using namespace std;

// This is greedy solution. DP is O(n^2).
int canJump(vector<int> &A) {
	int n = A.size();
	int max_reachable = 0;
	for(int i = 0; i < n; ++i) {
		if(max_reachable == n - 1) {
			return 1;
		}
		if(i > max_reachable) {
			return 0;
		}

		max_reachable = max(max_reachable, i + A[i]);
	}

	return 1; // this is never reached unless n == 0.
}

int main(void) {
	return 0;
}
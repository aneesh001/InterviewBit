#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
	sort(A.rbegin(), A.rend());

	int i = 0;
	while(i < A.size()) {
		if(i == A[i]) {
			return 1;
		}
		++i;

		while(A[i] == A[i - 1]) {
			++i;
		}
	}

	return -1;
}

int main(void) {
	vector<int> a{-4, -2, 0, -1, -6};
	cout << solve(a) << endl;
	return 0;
}
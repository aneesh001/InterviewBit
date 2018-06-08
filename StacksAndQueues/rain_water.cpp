#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int> &A) {
	vector<int> left_max(A.size(), 0), right_max(A.size(), 0);

	int m = 0;
	for(int i = 0; i < A.size(); ++i) {
		left_max[i] = m;
		m = max(m, A[i]);
	}

	m = 0;
	for(int i = A.size() - 1; i >= 0; --i) {
		right_max[i] = m;
		m = max(m, A[i]);
	}

	int ans = 0;
	for(int i = 0; i < A.size(); ++i) {
		ans += max(0, min(left_max[i], right_max[i]) - A[i]);
	}

	return ans;
}

int main(void) {

}
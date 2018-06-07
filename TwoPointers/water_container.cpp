#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &A) {
	int i = 0;
	int j = A.size() - 1;

	if(i == j) {
		return 0;
	}

	int ans = INT_MIN;

	while(i < j) {
		ans = max(min(A[i], A[j]) * (j - i), ans);

		if(A[i] < A[j]) {
			++i;
		}
		else {
			--j;
		}
	}

	return ans;
}

int main(void) {

}
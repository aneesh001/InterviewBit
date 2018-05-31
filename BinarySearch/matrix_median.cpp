#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
	int minm = INT_MAX, int maxm = INT_MIN;
	for(int i = 0; i < A.size(); ++i) {
		for(int j = 0; j < A[0].size(); ++j) {
			minm = min(minm, A[i][j]);
			maxm = max(maxm, A[i][j]);
		}
	}

	int low = minm, high = maxm;
	int n = A.size(); int m = A[0].size();
	int desired = (n * m) / 2 + 1;

	while(low < high) {
		int mid = (low + high) / 2;

		int lesser = 0;
		for(int i = 0; i < n; ++i) {
			lesser += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
		}

		if(lesser == desired) {
			break;
		}
		else if(lesser < desired) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return low;
}

int main(void) {

}
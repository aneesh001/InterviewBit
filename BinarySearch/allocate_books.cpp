#include <bits/stdc++.h>
using namespace std;

bool can_distribute(vector<int> &A, int B, int p) {
	int maxm = INT_MIN;
	for(int i = 0; i < A.size(); ++i) {
		maxm = max(maxm, A[i]);
	}

	if(maxm > p) {
		return false;
	}

	int count = 1;
	int sum = 0;

	for(int i = 0; i < A.size(); ) {
		if(sum + A[i] > p) {
			count++;
			sum = 0;
		}
		else {
			sum += A[i];
			i++;
		}
	}

	if(count <= B) {
		return true;
	}

	return false;
}

int books(vector<int> &A, int B) {
	int low = 0;
	int high = 0;
	for(int i = 0; i < A.size(); ++i) {
		high += A[i];
	}

	if(B > A.size()) {
		return -1;
	}

	int ans = INT_MAX;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(can_distribute(A, B, mid)) {
			ans = min(ans, mid);

			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return ans;
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
	sort(A.begin(), A.end());

	int ans = A[0] + A[1] + A[2];

	for(int i = 0; i < A.size(); ++i) {
		int to_find = B - A[i];

		int j = i + 1;
		int k = A.size() - 1;

		while(j < k) {
			if(A[j] + A[k] < to_find) {
				++j;
			}
			else if(A[j] + A[k] > to_find) {
				--k;
			}
			else {
				return B;
			}
		}

		if(j - 1 > i) {
			int sum = A[i] + A[j - 1] + A[j];

			ans = (abs(B - ans) > abs(B - sum)) ? sum : ans;
		}

		if(j + 1 < A.size()) {
			int sum = A[i] + A[j + 1] + A[j];

			ans = (abs(B - ans) > abs(B - sum)) ? sum : ans;
		}
	}

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int b;
	cin >> b;

	cout << threeSumClosest(arr, b) << endl;

	return 0;
}
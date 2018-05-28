#include <bits/stdc++.h>
using namespace std;

vector<int> subUnsort(vector<int> &A) {
	int i = 0;
	for(; i < A.size() - 1; ++i) {
		if(A[i] > A[i + 1]) {
			break;
		}
	}

	if(i == A.size() - 1) return vector<int> {-1};

	int j = A.size() - 1;
	for(; j >= 1; --j) {
		if(A[j] < A[j - 1]) {
			break;
		}
	}

	if(j == 0) return vector<int> {-1};

	int minm = INT_MAX;
	int maxm = INT_MIN;
	for(int k = i; k <= j; ++k) {
		minm = min(minm, A[k]);
		maxm = max(maxm, A[k]);
	}

	while(i - 1 >= 0 && A[i - 1] > minm) {
		i--;
	}

	while(j + 1 < A.size() && A[j + 1] < maxm) {
		j++;
	}

	return vector<int> {i, j};
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = subUnsort(arr);
	for(int i: ans) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
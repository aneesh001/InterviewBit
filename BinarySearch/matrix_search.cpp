#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int>> &A, int B) {
	int n = A.size();
	int m = A[0].size();

	if(n == 0 || m == 0) {
		return 0;
	}

	int low = 0;
	int high = n - 1;

	while(low < high) {
		int mid = (low + high) / 2;

		if(mid == low || mid == high) {
			break;
		}

		if(A[mid][m - 1] == B) {
			return 1;
		}
		else if(A[mid][m - 1] < B) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	for(int i = low; i <= high; ++i) {
		for(int j = 0; j < m; ++j) {
			if(A[i][j] == B) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}

	int key;
	cin >> key;

	cout << searchMatrix(mat, key) << endl;

	return 0;
}
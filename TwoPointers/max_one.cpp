#include <bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B) {
	int i = 0;
	int j = 0;
	int r = B;

	int ans_idx = 0;
	int ans_len = 0;

	while(i < A.size() && j < A.size()) {
		if(A[j] == 1) {
			++j;
		}
		else if(A[j] == 0 && r > 0) {
			++j;
			--r;
		}
		else {
			while(i < j && A[i] == 1) {
				++i;
			}

			if(i == j) {
				while(i < A.size() && A[i] == 0) {
					++i;
				}
				j = i;
			}
			else {
				++i;
				++r;
			}
		}

		if(ans_len < (j - i)) {
			ans_len = j - i;
			ans_idx = i;
		}
	}

	vector<int> ans;
	for(int i = ans_idx; i < ans_idx + ans_len; ++i) {
		ans.push_back(i);
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

	int m;
	cin >> m;

	for(int i: maxone(arr, m)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
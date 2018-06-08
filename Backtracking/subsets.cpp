#include <bits/stdc++.h>
using namespace std;

struct comp {
	bool operator()(const vector<int> &a, const vector<int> &b) {
		if(a.size() == 0) {
			return true;
		}
		else if(b.size() == 0) {
			return false;
		}
		else {
			int i = 0;
			int j = 0;

			while(i < a.size() && j < b.size()) {
				if(a[i] != b[j]) {
					return a[i] < b[j];
				}

				++i;
				++j;
			}

			if(i == a.size() && j != b.size()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

vector<vector<int>> subsets(vector<int> &A) {
	sort(A.begin(), A.end());

	vector<vector<int>> ans(1, vector<int>());

	for(int i = 0; i < A.size(); ++i) {
		vector<vector<int>> new_set;
		for(auto v: ans) {
			v.push_back(A[i]);
			new_set.push_back(v);
		}

		for(auto &v: new_set) {
			ans.push_back(v);
		}
	}

	sort(ans.begin(), ans.end(), comp());

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for(auto &v: subsets(arr)) {
		for(int i: v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
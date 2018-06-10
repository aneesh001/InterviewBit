#include <bits/stdc++.h>
using namespace std;

struct comp {
	bool operator()(const vector<int> &a, const vector<int> &b) {
		for(int i = 0; i < a.size(); ++i) {
			if(a[i] != b[i]) {
				return a[i] < b[i];
			}
		}

		return false;
	}
};

vector<vector<int>> combine(int A, int B) {
	vector<vector<int>> ans;

	if(B == 0 || A == 0) {
		ans.push_back(vector<int>());
		return ans;
	}

	for(auto &v: combine(A - 1, B)) {
		if(v.size() == B)
			ans.push_back(v);
	}

	for(auto &v: combine(A - 1, B - 1)) {
		v.push_back(A);

		if(v.size() == B)
			ans.push_back(v);
	}

	sort(ans.begin(), ans.end(), comp());

	return ans;
}

int main(void) {
	int n, k;
	cin >> n >> k;

	for(auto &v: combine(n, k)) {
		for(int i: v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
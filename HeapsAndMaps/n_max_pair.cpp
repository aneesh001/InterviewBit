#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
	vector<int> ans;
	int n = A.size();
	if(n <= 0) return ans;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	priority_queue<pair<int, pair<int, int>>> sums;
	set<pair<int, int>> seen;
	sums.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
	seen.insert({n - 1, n - 1});

	while(ans.size() < n) {
		pair<int, pair<int, int>> top = sums.top();
		sums.pop();

		int i = top.second.first;
		int j = top.second.second;

		ans.push_back(top.first);

		if(seen.find({i - 1, j}) == seen.end()) {
			sums.push({A[i - 1] + B[j], {i - 1, j}});
			seen.insert({i - 1, j});
		}

		if(seen.find({i, j - 1}) == seen.end()) {
			sums.push({A[i] + B[j - 1], {i, j - 1}});
			seen.insert({i, j - 1});
		}
	}

	return ans;
}

int main(void) {
	return 0;
}
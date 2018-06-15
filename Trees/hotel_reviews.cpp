#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string A, vector<string> &B) {
	unordered_set<string> gw;
	for(int i = 0; i < A.size(); ++i) {
		string w;
		while(i < A.size() && A[i] != '_') {
			w += A[i];
			++i;
		}
		gw.insert(w);
	}

	vector<pair<int, int>> reviews;
	for(int i = 0; i < B.size(); ++i) {
		int count = 0;
		for(int j = 0; j < B[i].size(); ++j) {
			string w;
			while(j < B[i].size() && B[i][j] != '_') {
				w += B[i][j];
				++j;
			}
			if(gw.find(w) != gw.end()) {
				count++;
			}
		}
		reviews.push_back({count, i});
	}
	stable_sort(reviews.begin(), reviews.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.first > b.first;
	});

	vector<int> ans;
	for(auto &p: reviews) {
		ans.push_back(p.second);
	}

	return ans;
}

int main(void) {
	return 0;
}
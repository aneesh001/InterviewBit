#include <bits/stdc++.h>
using namespace std;

struct comp {
	bool operator()(const vector<string> &a, const vector<string> &b) {
		int i = 0;
		int j = 0;

		while(i < a.size() && j < b.size()) {
			if(a[i].size() != b[j].size()) {
				return a[i].size() < b[i].size();
			}
			++i;
			++j;
		}

		if(i == a.size()) {
			return true;
		}
		else {
			return false;
		}
	}
};

bool is_pal(const string &a, int i, int j) {
	while(i < j) {
		if(a[i] != a[j]) {
			return false;
		}
		++i;
		--j;
	}
	return true;
}

void util(string &A, int s, vector<string> &cur, vector<vector<string>> &ans) {
	if(s >= A.size()) {
		ans.push_back(cur);
		return;
	}

	for(int i = s; i < A.size(); ++i) {
		if(is_pal(A, s, i)) {
			cur.push_back(A.substr(s, i - s + 1));
			util(A, i + 1, cur, ans);
			cur.pop_back();
		}
	}
}

vector<vector<string>> partition(string A) {
    vector<vector<string>> ans;
    vector<string> current;
    util(A, 0, current, ans);

    sort(ans.begin(), ans.end(), comp());

    return ans;
}

int main(void) {
	string s;
	cin >> s;

	for(auto &v: partition(s)) {
		for(auto &str: v) {
			cout << str << " ";
		}
		cout << endl;
	}

	return 0;
}
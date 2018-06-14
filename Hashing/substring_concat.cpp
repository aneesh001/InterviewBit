#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
	vector<int> ans;
	int total_len = 0;
	for(const string &s: B) {
		total_len += s.size();
	}
	if(total_len > A.size()) {
		return ans;
	}
	int single_len = B[0].size();
	unordered_map<string, int> mp;
	for(const string &s: B) {
		mp[s]++;
	}
	for(int i = 0; i <= A.size() - total_len; ++i) {
		unordered_map<string, int> mp2(mp);
		for(int j = i; j < i + total_len; j += single_len) {
			string s = A.substr(j, single_len);
			if(mp2.find(s) == mp2.end()) {
				break;
			}
			mp2[s]--;
		}
		int c = 0;
		for(auto &p: mp2) {
			if(p.second > 0) {
				c++;
				break;
			}
		}
		if(c == 0) {
			ans.push_back(i);
		}
	}
	return ans;
}

int main(void) {
	return 0;
}
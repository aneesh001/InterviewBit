#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B) {
	unordered_set<string> dict;
	for(string &s: B) dict.insert(s);
	int n = A.size();

	bool dp[n + 1];
	memset(dp, 0, n + 1);
	dp[0] = true;
	for(int i = 1; i <= n; ++i) {
		if(dict.find(A.substr(0, i)) != dict.end()) {
			dp[i] = true;
			continue;
		}

		bool flag = false;
		for(int j = i; j >= 1; --j) {
			if(dict.find(A.substr(j - 1, i - j + 1)) != dict.end() && 
				dp[j - 1] == true) {
				dp[i] = true;
				flag = true;
			}

			if(flag) break;
		}
	}

	return dp[n];
}

int main(void) {
	string text;
	cin >> text;

	int n;
	cin >> n;
	vector<string> words(n);
	for(int i = 0; i < n; ++i) {
		cin >> words[i];
	}

	cout << wordBreak(text, words) << endl;

	return 0;
}
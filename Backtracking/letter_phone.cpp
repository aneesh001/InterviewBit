#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> m;
string current;

void util(string &A, int i, vector<string> &ans) {
	if(i >= A.size()) {
		ans.push_back(current);
		return;
	}

	for(char ch: m[A[i]]) {
		current.push_back(ch);
		util(A, i + 1, ans);
		current.pop_back();
	}
}

vector<string> letterCombinations(string A) {
	m.insert({'1', vector<char>{'1'}});
	m.insert({'2', vector<char>{'a', 'b', 'c'}});
	m.insert({'3', vector<char>{'d', 'e', 'f'}});
	m.insert({'4', vector<char>{'g', 'h', 'i'}});
	m.insert({'5', vector<char>{'j', 'k', 'l'}});
	m.insert({'6', vector<char>{'m', 'n', 'o'}});
	m.insert({'7', vector<char>{'p', 'q', 'r', 's'}});
	m.insert({'8', vector<char>{'t', 'u', 'v'}});
	m.insert({'9', vector<char>{'w', 'x', 'y', 'z'}});
	m.insert({'0', vector<char>{'0'}});

	vector<string> ans;
	util(A, 0, ans);

	sort(ans.begin(), ans.end());

	return ans;
}

int main(void) {
	string s;
	cin >> s;

	for(string a: letterCombinations(s)) {
		cout << a << endl;
	}

	return 0;
}
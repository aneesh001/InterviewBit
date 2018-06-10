#include <bits/stdc++.h>
using namespace std;

void util(string &current, vector<string> &ans, int i, int j, int A) {
	if(i == A && j == A) {
		ans.push_back(current);
		return;
	}

	if(i < A) {
		current.push_back('(');
		util(current, ans, i + 1, j, A);
		current.pop_back();
	}

	if(j < A && i > j) {
		current.push_back(')');
		util(current, ans, i, j + 1, A);
		current.pop_back();
	}
}

vector<string> generateParenthesis(int A) {
	vector<string> ans;
	string current;
	util(current, ans, 0, 0, A);

	sort(ans.begin(), ans.end());

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	for(string &s: generateParenthesis(n)) {
		cout << s << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string A) {
	int i = 0;
	stack<string> path;

	while(i < A.size() && A[i] == '/') {
		++i;
	}

	while(i < A.size()) {
		string next;

		while(i < A.size() && A[i] != '/') {
			next += A[i];
			++i;
		}
		
		while(i < A.size() && A[i] == '/') {
			++i;
		}

		if(next == ".") {
			continue;
		}
		else if(next == "..") {
			if(!path.empty()) {
				path.pop();
			}
		}
		else {
			path.push(next);
		}
	}

	vector<string> ans;
	while(!path.empty()) {
		ans.push_back(path.top());
		path.pop();
	}

	string ret;
	for(int i = ans.size() - 1; i >= 0; --i) {
		ret += "/";
		ret += ans[i];
	}

	if(ret.empty()) {
		ret += "/";
	}

	return ret;
}

int main(void) {
	string s;
	cin >> s;

	cout << simplifyPath(s) << endl;

	return 0;
}
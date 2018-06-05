#include <bits/stdc++.h>
using namespace std;

vector<string> prettyJSON(string A) {
	vector<string> ans;

	string line;
	string indent;
	for(int i = 0; i < A.size(); ++i) {
		if(A[i] == ' ') {
			continue;
		}
		else if(A[i] == '[' || A[i] == '{') {
			if(line.size() > indent.size()) {
				ans.push_back(line);
			}

			ans.push_back(indent + A[i]);
			line.clear();
			indent += '\t';
			line += indent;
		}
		else if(A[i] == ',') {
			line += A[i];
			ans.push_back(line);
			line.clear();
			line += indent;
		}
		else if(A[i] == ']' || A[i] == '}') {
			if(line.size() > indent.size()) {
				ans.push_back(line);
			}

			indent.pop_back();
			line.clear();
			line += indent;

			if(i + 1 < A.size() && A[i + 1] == ',') {
				ans.push_back(indent + A[i] + ",");
				++i;
			}
			else {
				ans.push_back(indent + A[i]);
			}
		}
		else {
			line += A[i];
		}
	}

	return ans;
}

int main(void) {
	string s;
	cin >> s;

	for(string &line: prettyJSON(s)) {
		cout << line << endl;
	}

	return 0;
}
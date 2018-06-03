#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &A) {
	if(A.size() == 0) {
		return "";
	}

	string ans;
	int i = 0;

	while(true) {
		if(i >= A[0].size()) {
			break;
		}

		char c = A[0][i];

		int j;
		for(j = 1; j < A.size(); ++j) {
			if(i >= A[j].size() || A[j][i] != c) {
				break;
			}
		}

		if(j < A.size()) {
			break;
		}
		else {
			ans += c;
			i++;
		}
	}

	return ans;
}

int main(void) {

}
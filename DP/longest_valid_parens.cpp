#include <bits/stdc++.h>
using namespace std;

// O(n^2) is easy. This is hard.
int longestValidParentheses(string A) {
	int n = A.size();
	stack<int> st;
	st.push(-1);

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(A[i] == '(') {
			st.push(i);
		}
		else {
			st.pop();

			if(!st.empty()) {
				ans = max(ans, i - st.top());
			}
			else {
				st.push(i);
			}
		}
	}

	return ans;
}

int main(void) {
	string s;
	cin >> s;

	cout << longestValidParentheses(s) << endl;
	return 0;
}
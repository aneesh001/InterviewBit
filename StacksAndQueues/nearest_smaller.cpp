#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
	vector<int> ans;
	stack<int> st;

	for(int i = 0; i < A.size(); ++i) {
		while(!st.empty() && st.top() >= A[i]) {
			st.pop();
		}

		if(st.empty()) {
			ans.push_back(-1);
		}
		else {
			ans.push_back(st.top());
		}

		st.push(A[i]);
	}

	return ans;
}

int main(void) {

}
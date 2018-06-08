#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
	stack<int> vals;

	for(int i = 0; i < A.size(); ++i) {
		if(A[i].size() > 1 || (isdigit(A[i][0]))) {
			vals.push(stoi(A[i]));
		}
		else {
			int v1 = vals.top();
			vals.pop();

			int v2 = vals.top();
			vals.pop();

			if(A[i] == "+") {
				vals.push(v1 + v2);
			}
			else if(A[i] == "-") {
				vals.push(v1 - v2);
			}
			else if(A[i] == "*") {
				vals.push(v1 * v2);
			}
			else {
				vals.push(v1 / v2);
			}
		}
	}

	return vals.top();
}

int main(void) {

}
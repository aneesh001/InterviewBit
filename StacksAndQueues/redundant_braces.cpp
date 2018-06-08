#include <bits/stdc++.h>
using namespace std;

int braces(string A) {
	stack<int> st;

	for(int i = 0; i < A.size(); ++i) {
		if(A[i] != ')') {
			st.push(A[i]);
		}
		else {
			bool op = false;

			while(st.top() != '(') {
				if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
					op = true;
				}

				st.pop();
			}
			st.pop();

			if(!op) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {

}
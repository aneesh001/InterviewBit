#include <bits/stdc++.h>
using namespace std;

int isNumber(const string A) {
	int i = 0;

	// remove whitespace
	while(i < A.size() && A[i] == ' ') {
		++i;
	}

	if(i == A.size()) {
		return 0;
	}

	// skip minus or plus sign
	if(A[i] == '-' || A[i] == '+') {
		++i;
	}

	if(i == A.size()) {
		return 0;
	}

	// validate number till 'e' is found or end is reached.
	while(i < A.size() && A[i] != 'e') {
		if(isdigit(A[i])) {
			++i;
		}
		else if(A[i] == '.' && i + 1 < A.size() && isdigit(A[i + 1])) {
			++i;
		}
		else {
			return 0;
		}
	}

	// end reached we are done.
	if(i == A.size()) {
		return 1;
	}

	// nothing after 'e' => not a valid number.
	if(i + 1 == A.size()) {
		return 0;
	}

	++i;

	// skip minus or plus sign
	if(A[i] == '-' || A[i] == '+') {
		++i;
	}

	if(i == A.size()) {
		return 0;
	}

	// validate number till end is reached
	while(i < A.size()) {
		if(!isdigit(A[i])) {
			return 0;
		}
		++i;
	}

	return 1;
}

int main(void) {
	string s;
	cin >> s;

	cout << isNumber(s) << endl;

	return 0;
}
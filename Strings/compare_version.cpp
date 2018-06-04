#include <bits/stdc++.h>
using namespace std;

int compareStrings(const string &a, const string &b) {
	int i = 0;
	int j = 0;

	while(i < a.size() && a[i] == '0') {
		++i;
	}

	while(j < b.size() && b[j] == '0') {
		++j;
	}

	if(a.size() - i > b.size() - j) {
		return 1;
	}
	else if(a.size() - i < b.size() - j) {
		return -1;
	}
	else {
		while(i < a.size() && j < b.size()) {
			if(a[i] > b[j]) {
				return 1;
			}
			else if(a[i] < b[j]) {
				return -1;
			}

			++i; ++j;
		}

		return 0;
	}
}

int compareVersion(string A, string B) {
	int i = 0, j = 0;

	while(i < A.size() && j < B.size()) {
		string num1;
		string num2;

		while(i < A.size() && A[i] != '.') {
			num1 += A[i];
			++i;
		}

		while(j < B.size() && B[j] != '.') {
			num2 += B[j];
			++j;
		}

		int c = compareStrings(num1, num2);

		if(c != 0) return c;

		if(i < A.size() && A[i] == '.') {
			++i;
		}

		if(j < A.size() && B[j] == '.') {
			++j;
		}
	}

	if(i == A.size() && j == B.size()) {
		return 0;
	}
	else if(i != A.size()) {
		string end;
		while(i < A.size()) {
			if(A[i] == '.') {
				return 1;
			}
			end += A[i];
			++i;
		}

		if(compareStrings(end, "0") == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		string end;
		while(j < B.size()) {
			if(B[j] == '.') {
				return -1;
			}
			end += B[j];
			++j;
		}

		if(compareStrings(end, "0") == 0) {
			return 0;
		}
		else {
			return -1;
		}
	}
}

int main(void) {
	string v1, v2;
	cin >> v1 >> v2;

	cout << compareVersion(v1, v2) << endl;

	return 0;
}
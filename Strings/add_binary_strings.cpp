#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {
	string ans;
	int carry = 0;
	int i = A.size() - 1, j = B.size() - 1;

	while(i >= 0 && j >= 0) {
		int d = carry + (A[i] - '0') + (B[j] - '0');
		ans += to_string(d % 2);
		carry = d / 2;

		--i;
		--j;
	}

	while(i >= 0) {
		int d = carry + (A[i] - '0');
		ans += to_string(d % 2);
		carry = d / 2;

		--i;
	}

	while(j >= 0) {
		int d = carry + (B[j] - '0');
		ans += to_string(d % 2);
		carry = d / 2;

		--j;
	}

	if(carry) {
		ans += to_string(carry);
	}

	return string(ans.rbegin(), ans.rend());
}

int main(void) {
	string a, b;
	cin >> a >> b;

	cout << addBinary(a, b) << endl;

	return 0;
}
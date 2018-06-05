#include <bits/stdc++.h>
using namespace std;

void divide(string &num) {
	int carry = 0;
	string ans;

	for(int i = 0; i < num.size(); ++i) {
		int s = carry * 10 + (num[i] - '0');

		if(s / 2 > 0 || (s / 2 == 0 && i != 0)) {
			ans += to_string(s / 2);
		}

		carry = s % 2;
	}

	num = ans;
}

bool is_even(const string &num) {
	return (num[num.size() - 1] - '0') % 2 == 0;
}

int power(string A) {
	if(A == "0") {
		return 0;
	}
	else if(A == "1") {
		return 0;
	}

	while(is_even(A)) {
		divide(A);
	}

	if(A == "1") {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	string s;
	cin >> s;

	cout << power(s) << endl;

	return 0;
}
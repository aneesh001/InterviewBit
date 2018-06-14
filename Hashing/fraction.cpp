#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int A, int B) {
	int sign = 1;
	if(A < 0 && B > 0) {
		sign = -1;
	}
	else if(A > 0 && B < 0) {
		sign = -1;
	}

	long long n = A;
	long long d = B;
	n = abs(n);
	d = abs(d);

	string ans;
	ans += to_string(n / d);

	if(n % d == 0) {
		return ((sign == -1) ? ("-" + ans) : (ans));
	}

	ans += ".";
	
	vector<long long> rem;
	unordered_set<long long> seen;
	long long r = n % d;

	while(r != 0 && seen.find(r) == seen.end()) {
		rem.push_back(r);
		seen.insert(r);

		r = (10 * r) % d;
	}

	for(int i = 0; i < rem.size(); ++i) {
		if(rem[i] == r && r != 0) {
			ans += "(";
		}
		ans += to_string((rem[i] * 10) / d);
	}
	if(r != 0) {
		ans += ")";
	}

	if(sign == -1) {
		ans = "-" + ans;
	}
	return ans;
}

int main(void) {
	int a, b;
	cin >> a >> b;

	cout << fractionToDecimal(a, b) << endl;
	return 0;
}
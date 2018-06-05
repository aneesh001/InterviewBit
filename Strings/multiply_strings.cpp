#include <bits/stdc++.h>
using namespace std;

string multiply(string A, string B) {
	if(A == "0" || B == "0") {
		return "0";
	}

	int imin = 0;
	int jmin = 0;
	while(imin < A.size() && A[imin] == '0') {
		++imin;
	}
	while(jmin < B.size() && B[jmin] == '0') {
		++jmin;
	}

	string ans;
	int z = 0;
	for(int i = A.size() - 1; i >= imin; --i) {
		if(A[i] != '0') {
			string tmp;
			int carry = 0;
			// int z = A.size() - (i + 1);

			for(int j = B.size() - 1; j >= jmin; --j) {
				int s = carry + ((A[i] - '0') * (B[j] - '0'));
				tmp += (s % 10) + '0';
				carry = s / 10;
			}

			while(carry) {
				tmp += (carry % 10) + '0';
				carry = carry / 10;
			}

			reverse(tmp.begin(), tmp.end());

			for(int zi = 0; zi < z; ++zi) {
				tmp += '0';
			}

			string add;
			int a = ans.size() - 1;
			int b = tmp.size() - 1;
			assert(carry == 0);

			while(a >= 0 || b >= 0) {
				int s = carry;
				if(a >= 0) {
					s += ans[a--] - '0';
				}
				if(b >= 0) {
					s += tmp[b--] - '0';
				}

				add += (s % 10) + '0';
				carry = s / 10;
			}

			while(carry) {
				add += (carry % 10) + '0';
				carry = carry / 10;
			}

			reverse(add.begin(), add.end());
			ans = add;
		}

		z += 1;
	}

	return ans;
}

int main(void) {
	string a, b;
	cin >> a >> b;

	cout << multiply(a, b) << endl;

	return 0;
}
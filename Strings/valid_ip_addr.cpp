#include <bits/stdc++.h>
using namespace std;

int to_int(string &s, int i, int j) {
	int ans = 0;
	for(int p = i; p <= j; ++p) {
		ans = 10 * ans + (s[p] - '0');
	}
	return ans;
}

bool in_range(int num) {
	return num >= 0 && num <= 255;
}

vector<string> restoreIpAddresses(string A) {
	vector<string> ans;

	if(A.size() > 12) {
		return ans;
	}

	int n = A.size();

	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j < n - 1; ++j) {
			for(int k = j + 1; k < n - 1; ++k) {
				int num1 = to_int(A, 0, i);
				int num2 = to_int(A, i + 1, j);
				int num3 = to_int(A, j + 1, k);
				int num4 = to_int(A, k + 1, n - 1);

				if(in_range(num1) && in_range(num2) && in_range(num3) && in_range(num4)) {
					string to_add = to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);

					if(to_add.size() == 3 + A.size()) {
						ans.push_back(to_add);
					}
				}
			}
		}
	}

	return ans;
}

int main(void) {
	string s;
	cin >> s;

	for(string ip: restoreIpAddresses(s)) {
		cout << ip << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string A) {
	if(A.size() == 0) {
		return "";
	}

	int ans_len = 1;
	int ans_idx = 0;

	unordered_map<int, vector<int>> mem;
	mem.insert({1, vector<int>(A.size(), true)});

	for(int len = 2; len <= A.size(); ++len) {
		if(len == 2) {
			vector<int> nm(A.size(), false);
			for(int i = 0; i <= A.size() - 2; ++i) {
				if(A[i] == A[i + 1]) {
					nm[i] = true;

					if(ans_len < 2) {
						ans_len = 2;
						ans_idx = i;
					}
				}
			}

			mem.insert({2, nm});
		}
		else {
			vector<int> nm(A.size(), false);

			for(int i = 0; i <= A.size() - len; ++i) {
				int j = i + len - 1;

				if(A[i] == A[j] && mem[len - 2][i + 1]) {
					nm[i] = true;

					if(ans_len < len) {
						ans_len = len;
						ans_idx = i;
					}
				}
			}

			mem.insert({len, nm});
			mem.erase(len - 2);
		}
	}

	return A.substr(ans_idx, ans_len);
}

int main(void) {
	string s;
	cin >> s;

	cout << longestPalindrome(s) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool is_pal(const string &s, int i, int j) {
	int low = i;
	int high = j;
	while(low < high) {
		if(s[low] != s[high]) {
			return false;
		}

		low++;
		high--;
	}

	return true;
}

int minCut(string A) {
	int n = A.size();
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for(int i = 1; i <= n; ++i) {
		if(is_pal(A, 0, i - 1)) {
			dp[i] = 0;
			continue;
		}

		for(int j = i; j >= 1; --j) {
			if(is_pal(A, j - 1, i - 1)) {
				dp[i] = min(dp[i], 1 + dp[j - 1]);
			}
		}
	}

	return (dp[n] == INT_MAX) ? n : dp[n];
}

int main(void) {
	string s;
	cin >> s;

	cout << minCut(s) << endl;
	return 0;
}
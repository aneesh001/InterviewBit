#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A) {
	if(A.size() <= 0) return 0;
	int n = A.size();
	int m = A[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	
	for(int c = 0; c < m; ++c) {
		for(int r = 0; r < n; ++r) {
			if(A[r][c] == 1) {
				dp[r][c] = A[r][c] + ((r - 1 >= 0) ? dp[r - 1][c] : 0);
			}
		}
	}

	for(int r = 0; r < n; ++r) {
		sort(dp[r].begin(), dp[r].end(), greater<int>());
	}

	int ans = INT_MIN;
	for(int r = 0; r < n; ++r) {
		for(int c = 0; c < m; ++c) {
			ans = max(ans, (c + 1) * dp[r][c]);
		}
	}

	return ans;
}

int main(void) {
	vector<vector<int>> q;
	q.push_back({0, 1, 0, 1, 0});
	q.push_back({0, 1, 0, 1, 1});
	q.push_back({1, 1, 0, 1, 0});

	cout << solve(q) << endl;
	return 0;
}
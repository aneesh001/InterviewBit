#include <bits/stdc++.h>
using namespace std;

const int MOD = int(10E9) + 7;
const int MAXN = 101;
long ncr[MAXN][MAXN];

void precompute() {
	for(int n = 0; n < MAXN; ++n) {
		for(int r = 0; r <= n; ++r) {
			if(n == 0) ncr[0][r] = 0;
			else if(r == 0 || r == n) ncr[n][r] = 1;
			else ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
		}
	}
}

int left_size(int n) {
	int h = int(log(n) / log(2));
	int m = int(pow(2, h));
	int p = n - (int(pow(2, h)) - 1);
	if(p >= m / 2) {
		return int(pow(2, h)) - 1;
	}
	else {
		return int(pow(2, h)) - 1 - (m / 2 - p);
	}
}

long util(int n) {
	if(n == 1 || n == 0) return 1;

	int left = left_size(n);
	int right = n - 1 - left;

	return (((ncr[n - 1][left] * util(left)) % MOD) * util(right)) % MOD;
}

int solve(int A) {
	precompute();
	return util(A);
}

int main(void) {
	int n;
	cin >> n;

	cout << solve(n) << endl;
	return 0;
}
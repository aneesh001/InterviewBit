#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	int ans = 1;
	for(int i = 2; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

int npr(int n, int r) {
	return fact(n) / fact(n - r);
}

int solve(vector<int> &A, int B, int C) {
	vector<int> digits;
	while(C) {
		digits.push_back(C % 10);
		C /= 10;
	}

	int i = 0, j = digits.size() - 1;
	while(i < j) {
		int tmp = digits[i];
		digits[i] = digits[j];
		digits[j] = tmp;

		++i;
		--j;
	}

	if(B > digits.size() || B > A.size()) {
		return 0;
	}
	else if(B < digits.size()) {
		int all = npr(A.size(), B);
		if(A[0] == 0) {
			all -= npr(A.size() - 1, B - 1);
		}
		return all;
	}
	else {
		int all = 0;
		unordered_set<int> removed;
		for(int i = 0; i < digits.size(); ++i) {
			int c = 0;
			int j = 0;
			while(j < A.size() && A[j] < digits[i]) {
				if(removed.find(A[j]) == removed.end()) {
					c++;
				}

				++j;
			}

			all += c * npr(A.size() - 1, digits.size() - i - 1);
			if(A[i] == 0) {
				all -= npr(A.size() - 1, digits.size() - i - 1);
			}

			removed.insert(digits[i]);
		}

		return all;
	}
}

int main(void) {

}
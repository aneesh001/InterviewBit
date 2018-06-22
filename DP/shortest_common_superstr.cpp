#include <bits/stdc++.h>
using namespace std;

int overlap(const string &a, const string &b, string &res) {
	int max = INT_MIN;
	int n1 = a.size();
	int n2 = b,size();

	for(int i = 1; i <= min(n1, n2); ++i) {
		if(a.compare(0, i, b, n2 - i, i) == 0 && i > max) {
			max = i;
			res = b + a.substr(i);
		}
	}

	for(int i = 1; i <= min(n1, n2); ++i) {
		if(a.compare(n1 - i, i, b, 0, i) == 0 && i > max) {
			max = i;
			res = a + b.substr(i);
		}
	}

	return max;
}

// NP Hard! Wtf??? Stupid interview bit.
int solve(vector<string> &A) {
	if(A.size() == 0) return 0;

	int n = A.size();

	while(n != 1) {
		int max = INT_MIN;
		int l, r;
		string res;

		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				string ans;
				int ol = overlap(A[i], A[j], ans);
				if(ol > max) {
					max = ol;
					res = ans;
					l = i;
					r = j;
				}
			}
		}

		n--;
		if(max == INT_MIN) {
			A[0] += A[n];
		}
		else {
			A[l] = res;
			A[r] = A[n];
		}
	}

	return A[0].size();
}

int main(void) {
	return 0;
}
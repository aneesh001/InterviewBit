#include <bits/stdc++.h>
using namespace std;

bool are_equal(int c[256], int d[256]) {
	for(int i = 0; i < 256; ++i) {
		if(a[i] < b[i]) {
			return false;
		}
	}

	return true;
}

string minWindow(string A, string B) {
	int acount[256];
	int bcount[256];

	for(int i = 0; i < 256; ++i) {
		acount[i] = bcount[i] = 0;
	}

	for(int i = 0; i < B.size(); ++i) {
		bcount[B[i]]++;
	}

	int i = 0, j = 0;
	int ans_len = INT_MAX;
	int ans_idx = INT_MAX;
	while(i < A.size() && j < A.size()) {
		while(j < A.size() && !are_equal(acount, bcount)) {
			acount[A[j]]++;
			j++;
		}

		while(i < j && are_equal(acount, bcount)) {
			acount[A[i]]--;
			i++;
		}

		if(ans_len > j - i + 1) {
			ans_len = j - i + 1;
			ans_idx = i - 1;
		}
		else if(ans_len == j - i + 1) {
			ans_idx = min(ans_idx, i - 1);
		}
	}

	if(ans_idx < 0 || ans_idx >= A.size() || ans_len > A.size()) {
		return "";
	}
	else {
		return A.substr(ans_idx, ans_len);
	}
}

int main(void) {
	string a, b;
	cin >> a >> b;
	
	cout << minWindow(a, b) << endl;
	return 0;
}
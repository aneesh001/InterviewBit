#include <bits/stdc++.h>
using namespace std;

bool is_pal(string &s, int e) {
	int low = 0;
	int high = e;

	while(low < high) {
		if(s[low] != s[high]) {
			return false;
		}

		++low;
		--high;
	}

	return true;
}

int solve(string A) {
	int e = A.size() - 1;
	int ans = 0;

	while(!is_pal(A, e)) {
		e--;
		ans++;
	}

	return ans;
}

int main(void) {
	string s;
	cin >> s;

	cout << solve(s) << endl;

	return 0;
}
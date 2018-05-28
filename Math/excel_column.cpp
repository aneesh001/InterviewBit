#include <bits/stdc++.h>
using namespace std;

int char_to_int(char ch) {
	return ch - 'a' + 1;
}

int titleToNumber(string A) {
	int ans = 0;
	for(int i = 0; i < A.size(); ++i) {
		ans = ans * 26 + char_to_int(A[i]);
	}
	return ans;
}

int main(void) {
	convertToTitle(1);
}
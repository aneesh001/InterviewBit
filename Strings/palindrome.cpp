#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A) {
	string n;
	for(int i = 0; i < A.size(); ++i) {
		if(isalnum(A[i])) {
			n += tolower(A[i]);
		}
	}

	cout << n << endl;

	int low = 0;
	int high = n.size() - 1;

	while(low < high) {
		if(n[low] != n[high]) {
			return 0;
		}
		++low;
		--high;
	}

	return 1;
}

int main(void) {
	cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
	return 0;
}
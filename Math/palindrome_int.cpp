#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int A) {
	if(A < 0)
		return 0;

	int num = 0;
	int tmp = A;

	while(tmp) {
		num = (num * 10) + (tmp % 10);
		tmp /= 10;
	}

	if(num == A) return 1;
	else return 0;
}

int main(void) {
	int n;
	cin >> n;

	cout << isPalindrome(n) << endl;

	return 0;
}
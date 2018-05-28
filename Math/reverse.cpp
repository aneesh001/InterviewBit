#include <bits/stdc++.h>
using namespace std;

int reverse(int A) {
	int sign = (A < 0) ? -1 : 1;
	A = (A < 0) ? -A : A;

	long ans = 0;

	while(A) {
		int d = A % 10;
		ans = ans * 10 + d;
		A /= 10;
	}

	if(ans > INT_MAX) {
		return 0;
	}
	else if(sign == -1 && ans > -1 * INT_MIN) {
		return 0;
	}
	else {
		return (int)(sign * ans);
	}
}

int main(void) {

}
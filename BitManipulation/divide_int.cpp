#include <bits/stdc++.h>
using namespace std;

int divide(int A, int B) {
	long a = abs(A);
	long b = abs(B);
	long s = 0;
	int sign_a = ((A & (1 << 31)) == 0) ? 0 : 1;
	int sign_b = ((B & (1 << 31)) == 0) ? 0 : 1;
	int sign = sign_a ^ sign_b;

	int times = 0;

	while(s + b <= a) {
		s += b;
		times++;
	}

	// cout << times << " " << sign << endl;

	if(s > INT_MAX) {
		return INT_MAX;
	}
	else {
		if(sign) {
			times = -times;
		}

		return times;
	}
}

int main(void) {
	cout << divide(5, 2) << endl;

	return 0;
}
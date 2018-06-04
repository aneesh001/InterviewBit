#include <bits/stdc++.h>
using namespace std;

int atoi(const string A) {
	int i = 0;
	while(i < A.size() && A[i] == ' ') {
		++i;
	}

	if(i == A.size()) {
		return 0;
	}

	if(!isdigit(A[i]) && A[i] != '-' && A[i] != '+') {
		return 0;
	}

	int sign = 1;
	if(A[i] == '-') {
		sign = -1;
		++i;
	}
	else if(A[i] == '+') {
		sign = 1;
		++i;
	}

	long ans = 0;
	long max = (sign == 1) ? INT_MAX : INT_MIN;
	while(i < A.size() && isdigit(A[i])) {
		ans = 10 * ans + (A[i] - '0');
		++i;

		if(ans > abs(max)) {
			return max;
		}
	}

	return (int)(sign * ans);
}

int main(void) {

}
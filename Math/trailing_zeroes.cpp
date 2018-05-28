#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int A) {
	int ans = 0;
	int div = 5;

	while(A / div) {
		ans += A / div;
		div = 5 * div;
	}

	return ans;
}

int main(void) {

}
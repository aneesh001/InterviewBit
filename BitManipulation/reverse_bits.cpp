#include <bits/stdc++.h>
using namespace std;

unsigned int reverse(unsigned int A) {
    unsigned int ans = 0;
    unsigned int one = 1;

    for(int i = 0; i < 32; ++i) {
    	unsigned int bit = A & (one << i);
    	ans = (ans << 1) | ((bit > 0) ? 1 : 0);
    }

    return ans;
}

int main(void) {
	cout << reverse(UINT_MAX) << endl;

	return 0;
}
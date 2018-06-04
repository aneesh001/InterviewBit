#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int cntBits(vector<int> &A) {
	long ans = 0;

	for(int i = 0; i < 32; ++i) {
		long ones = 0;
		for(int j = 0; j < A.size(); ++j) {
			if(A[j] & (1 << i)) {
				ones++;
			}
		}

		ans = (ans + (ones * (A.size() - ones))) % MOD;
	}

	ans = (2 * ans) % MOD;

	return (int) ans;
}

int main(void) {

}
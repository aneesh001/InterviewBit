#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int solve(int A) {
	vector<ll> two(A, 0);
	vector<ll> three(A, 0);
	two[0] = 12;
	three[0] = 24;

	for(int i = 1; i < A; ++i) {
		two[i] = ((three[i - 1] * 5) + two[i - 1] * 7) % MOD;
		three[i] = ((three[i - 1] * 11) + (two[i - 1] * 10)) % MOD;
	}

	return (two[A - 1] + three[A - 1]) % MOD;
}

int main(void) {
	cout << "Hello world!" << endl;
	return 0;
}
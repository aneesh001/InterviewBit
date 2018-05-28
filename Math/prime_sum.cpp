#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num) {
	if(num == 1) return false;

	for(int i = 2; i * i <= num; ++i) {
		if(num % i == 0) {
			return false;
		}
	}

	return true;
}

vector<int> primesum(int A) {
	for(int i = 2; i <= A / 2; ++i) {
		int p = i;
		int q = A - i;

		if(is_prime(p) && is_prime(q)) {
			return vector<int>{p, q};
		}
	}

	return vector<int>{-1, -1};
}

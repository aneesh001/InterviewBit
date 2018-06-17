#include <bits/stdc++.h>
using namespace std;

const long mod = 1000000007;

int nchoc(int A, vector<int> &B) {
	priority_queue<long> pq(B.begin(), B.end());
	long ans = 0;
	
	while(A--) {
		long top = pq.top();
		pq.pop();

		ans = (ans + top) % mod;

		pq.push(top / 2);
	}

	return ans;
}

int main(void) {
	return 0;
}
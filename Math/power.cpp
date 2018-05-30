#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int isPower(int A) {
	vector<int> pows;

	int count = 0;
	while(A % 2 == 0) {
		count++;
		A = A / 2;
	}

	if(count) pows.push_back(count);

	for(int i = 3; i * i <= A; i += 2) {
		count = 0;
		while(A % i == 0) {
			count++;
			A = A / i;
		}

		if(count) pows.push_back(count);
	}

	if(A > 2) {
		pows.push_back(A);
	}

	if(pows.size() == 0) {
		return 0;
	}
	else {
		int g = pows[0];
		for(int i = 1; i < pows.size(); ++i) {
			g = gcd(g, pows[i]);
		}

		if(g == 1) return 0;
		else return 1;
	}
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int cpFact(int A, int B) {
	int g = gcd(A, B);

	while(g != 1) {
		A /= g;
		g = gcd(A, B);
	}

	return A;
}

int main(void) {

}
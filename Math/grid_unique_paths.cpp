#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int A, int B) {
    A--;
    B--;

    if(A == 0 || B == 0) return 1;

    long numer = 1;
    long denom = 1;
    for(long i = 1; i <= B; ++i) {
        numer *= (A + i);
        denom *= i;
    }

    return (int) (numer / denom);
}

int main(void) {
	int a, b;
	cin >> a >> b;

	cout << uniquePaths(a, b) << endl;

	return 0;
}
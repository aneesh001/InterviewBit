#include <bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {
    if(x == 0) return 0;
    if(n == 0) return 1;
    
    long res = 1;
    long pow = x;
    
    while(n > 0) {
        if(n % 2 != 0) {
            res = (res * pow + d) % d;
        }
        
        n = n / 2;
        pow = (pow * pow) % d;
    }
    
    return res;
}

int main(void) {
	cout << pow(71045970, 41535484, 64735492) << endl;

	return 0;
}
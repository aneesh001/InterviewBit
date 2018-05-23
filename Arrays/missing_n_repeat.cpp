#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    long a = 0, b = 0, a2 = 0, b2 = 0;
    for(int i = 1; i <= A.size(); ++i) {
        a += i;
        a2 += i * i;
        b += A[i - 1];
        b2 += (long)A[i - 1] * (long)A[i - 1];
    }
    
    long ypx = (a2 - b2) / (a - b);
    long ymx = a - b;
    
    long y = (ypx + ymx) / 2;
    long x = (ypx - ymx) / 2;
    
    // y - x = a - b
    // y + x = (a2 - b2) / (a - b)
    
    return vector<int>{(int)x, (int)y};
}

int main(void) {
	vector<int> a{3, 1, 2, 5, 3};
	repeatedNumber(a);
	return 0;
}
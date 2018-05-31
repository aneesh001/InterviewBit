#include <bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    int low = 0, high = A;

    while(low < high) {
    	int mid = (low + high) / 2;

    	if(mid == low || mid == high) {
    		break;
    	}

    	if(mid * mid == A) {
    		return mid;
    	}
    	else if(mid * mid > A) {
    		high = mid;
    	}
    	else {
    		low = mid;
    	}
    }

    if(high * high <= A) return high;
    else return low;
}

int main(void) {
	cout << sqrt(1) << endl;

	return 0;
}
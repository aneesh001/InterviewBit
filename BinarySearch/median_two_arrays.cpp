#include <bits/stc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
	int m = A.size();
	int n = B.size();

    int low = 0;
    int high = m;

    while(low <= high) {
    	int i = (low + high) / 2;
    	int j = (m + n + 1) / 2 - i;

    	if(B[j - 1] > A[i]) {
    		low = i + 1;
    	}
    	else if(A[i - 1] > B[j]) {
    		high = i - 1;
    	}
    	else {
    		if((m + n) % 2 != 0) {
    			return max(A[i - 1], B[j - 1]);
    		}
    		else {
    			return (max(A[i - 1], B[j - 1]) + min(A[i], B[j])) / 2.0;
    		}
    	}
    }
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {
    if(A.size() == 0) {
    	return 0;
    }

    int i = 0;
    int j = 1;
    int size = 1;
    int count = 1;

    while(j < A.size()) {
    	if(A[i] != A[j]) {
    		A[i + 1] = A[j];
    		++i;
    		++size;
    		count = 1;
    	}
    	else if(A[i] == A[j] && count < 2) {
    		A[i + 1] = A[j];
    		++i;
    		++size;
    		++count;
    	}

    	++j;
    }

    return size;
}

int main(void) {

}
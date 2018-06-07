#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {
    if(A.size() == 0) {
    	return 0;
    }

    int size = 1;
    int i = 0;
    int j = 1;

    while(j < A.size()) {
    	if(A[i] != A[j]) {
    		A[i + 1] = A[j];
    		++i;
    		++size;
    	}
    	++j;
    }

    return size;
}

int main(void) {

}
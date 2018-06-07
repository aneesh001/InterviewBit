#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A) {
    int i = -1;
    int j = 0;

    while(j < A.size()) {
    	if(A[j] == 0) {
    		int tmp = A[i + 1];
    		A[i + 1] = A[j];
    		A[j] = tmp;
    		++i;
    	}

    	++j;
    }

    j = i + 1;
    while(j < A.size()) {
    	if(A[j] == 1) {
    		int tmp = A[i + 1];
    		A[i + 1] = A[j];
    		A[j] = tmp;
    		++i;
    	}

    	++j;
    }

    j = i + 1;
    while(j < A.size()) {
    	if(A[j] == 2) {
    		int tmp = A[i + 1];
    		A[i + 1] = A[j];
    		A[j] = tmp;
    		++i;
    	}

    	++j;
    }
}

int main(void) {

}
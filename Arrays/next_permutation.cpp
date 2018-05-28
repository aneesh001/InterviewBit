#include <bits/stdc++.h>
using namespace std;

// n^2
void nextPermutation(vector<int> &A) {
	int i = A.size() - 2;
    for(; i >= 0; --i) {
    	int next = INT_MAX;
    	int index = -1;

    	for(int j = i + 1; j < A.size(); ++j) {
    		if(A[j] > A[i]) {
    			next = min(next, A[j]);
    			index = j;
    		}
    	}

    	if(next != INT_MAX) {
    		int tmp = A[i];
    		A[i] = A[index];
    		A[index] = tmp;
    		break;
    	}
    }

    sort(A.begin() + i + 1, A.end());
}

int main(void) {

}
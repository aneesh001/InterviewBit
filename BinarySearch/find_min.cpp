#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int> &A) {
    for(int i = 0; i < A.size() - 1; ++i) {
    	if(A[i] > A[i + 1]) {
    		return A[i + 1];
    	}
    }
}

int main(void) {

}
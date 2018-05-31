#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(const vector<int> &A, int B) {
    int i = lower_bound(A.begin(), A.end(), B) - A.begin();
    int j = upper_bound(A.begin(), A.end(), B) - A.begin();

    if(i > A.size() || A[i] != B) {
    	return vector<int> {-1, -1};
    }
    else {
    	return vector<int> {i, j - 1};
    }
}

int main(void) {

}
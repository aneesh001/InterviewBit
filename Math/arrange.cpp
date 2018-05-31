#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &A) {
    for(int i = 0; i < A.size(); ++i) {
    	A[i] = A[i] + A.size() * (A[A[i]] % A.size());
    }
    for(int i = 0; i < A.size(); ++i) {
    	A[i] = A[i] / A.size();
    }
}

int main(void) {
	vector<int> arr {4, 0, 2, 1, 3};
	arrange(arr);

	for(int i: arr) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
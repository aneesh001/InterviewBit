#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &A, int B) {
    int i = 0;
    while(i < A.size() && A[i] == B) {
    	++i;
    }

    if(i == A.size()) {
    	return 0;
    }

    if(i != 0) {
    	A[0] = A[i];
    	A[i] = B;
	}

    int j = i + 1;
    i = 0;
    int size = 1;

    while(j < A.size()) {
    	if(A[j] != B) {
    		A[i + 1] = A[j];
    		++i;
    		++size;
    	}

    	++j;
    }

    return size;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int r;
	cin >> r;

	int l = removeElement(arr, r);
	for(int i = 0; i < l; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
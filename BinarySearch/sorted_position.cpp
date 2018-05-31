#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &A, int B) {
    int i = lower_bound(A.begin(), A.end(), B) - A.begin();

    if(i < A.size() && A[i] == B) {
    	return i;
    }
    else {
    	while(i - 1 >= 0 && A[i - 1] > B) {
    		--i;
    	}

    	return i;
    }
}

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int k;
	cin >> k;

	cout << searchInsert(arr, k) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int search(const vector<int> &A, int B) {
    int low = 0;
    int high = A.size() - 1;

    while(low <= high) {
    	int mid = (low + high) / 2;

    	if(A[mid] == B) {
    		return mid;
    	}
    	else if(A[low] < A[high]) {
    		if(A[mid] < B) {
    			low = mid + 1;
    		}
    		else {
    			high = mid - 1;
    		}
    	}
    	else {
    		if(A[mid] < A[low] && B > A[mid] && B <= A[high]) {
    			low = mid + 1;
    		}
    		else if(A[mid] < A[low]) {
    			high = mid - 1;
    		}
    		else if(A[mid] > A[low] && B < A[mid] && B >= A[low]) {
    			high = mid - 1;
    		}
    		else {
    			low = mid + 1;
    		}
    	}
    }

    return -1;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int key;
	cin >> key;

	cout << search(arr, key) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int findCount(const vector<int> &A, int B) {
	int low = 0;
	int high = A.size() - 1;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(A[mid] == B) {
			int count = 1;
			for(int i = mid - 1; i >= 0; --i) {
				if(A[i] == B) count++;
				else break;
			}
			for(int i = mid + 1; i < A.size(); ++i) {
				if(A[i] == B) count++;
				else break;
			}
			return count;
		}
		else if(A[mid] > B) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return 0;
}

int main(void) {

}
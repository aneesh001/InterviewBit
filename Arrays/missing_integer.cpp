#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
	int i = 0;
	while(i < A.size() && A[i] <= 0) {
		++i;
	}

	if(i == A.size()) {
		return 1;
	}

	int tmp = A[i];
	A[i] = A[0];
	A[0] = tmp;

	int j = 1;
	i = 0;

	while(j < A.size()) {
		if(A[j] > 0) {
			int tmp = A[j];
			A[j] = A[i + 1];
			A[i + 1] = tmp;
			++i;
		}
		++j;
	}

	int size = i + 1;

	for(i = 0; i < size; i++) {
    	if(abs(A[i]) - 1 < size && A[abs(A[i]) - 1] > 0)
      		A[abs(A[i]) - 1] = -A[abs(A[i]) - 1];
  	}
 
  	for(i = 0; i < size; i++)
    	if(A[i] > 0)
      		return i + 1;
 
  	return size + 1;
}

int main(void) {
	vector<int> a {3, 4, -1, 1};

	cout << firstMissingPositive(a) << endl;

	return 0;
}
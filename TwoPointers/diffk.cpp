#include <bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B) {
	int i = 0, j = 1;

	for(; i < A.size() && j < A.size(); ++i) {
		if(j <= i) {
			j = i + 1;
		}

		while(j < A.size() && A[j] - A[i] < B) {
			++j;
		}

		if(A[j] - A[i] == B) {
			return 1;
		}
	}

	return 0;
}

int main(void) {

}
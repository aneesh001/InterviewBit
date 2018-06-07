#include <bits/stdc++.h>
using namespace std;

int nTriang(vector<int> &A) {
	sort(A.begin(), A.end());

	int count = 0;

	for(int i = 0; i < A.size() - 2; ++i) {
		int j = i + 2;

		for(int k = i + 1; k < A.size(); ++k) {
			while(j < A.size() && A[i] + A[k] > A[j]) {
				++j;
			}
		}

		count = (count + j - k - 1) % 1000000007;
	}

	return count;
}

int main(void) {

}
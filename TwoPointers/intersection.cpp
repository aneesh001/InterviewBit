#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
	vector<int> ans;

	int i = 0;
	int j = 0;

	while(i < A.size() && j < B.size()) {
		if(A[i] == B[j]) {
			ans.push_back(B[j]);
			++i;
			++j;
		}
		else if(A[i] < B[j]) {
			++i;
		}
		else {
			++j;
		}
	}

	return ans;
}

int main(void) {

}
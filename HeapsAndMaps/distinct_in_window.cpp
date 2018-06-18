#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B) {
	vector<int> ans;
	if(B > A.size()) {
		return ans;
	}

	map<int, int> distinct;
	for(int i = 0; i < B; ++i) {
		distinct[A[i]] += 1;
	}
	ans.push_back(distinct.size());

	for(int i = 1; i <= A.size() - B; ++i) {
		distinct[A[i - 1]] -= 1;
		if(distinct[A[i - 1]] <= 0) {
			distinct.erase(A[i - 1]);
		}
		distinct[A[i + B - 1]] += 1;
		ans.push_back(distinct.size());
	}

	return ans;
}

int main(void) {
	return 0;
}
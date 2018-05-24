#include <bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &A) {
	sort(A.begin(), A.end());

	for(int i = 0; i < A.size() - 1; i += 2) {
		int tmp = A[i];
		A[i] = A[i + 1];
		A[i + 1] = tmp;
	}

	vector<int> ans;
	for(int i: A) {
		ans.push_back(i);
	}
	return ans;
}

int main(void) {
	vector<int> a {1, 2, 3, 4, 5};
	for(int i: wave(a)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
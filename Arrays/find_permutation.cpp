#include <bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B) {
	vector<int> ans;
	int min = 1;
	int max = B;

	for(int i = 0; i < A.size(); ++i) {
		if(A[i] == 'I') {
			ans.push_back(min++);
		}
		else {
			ans.push_back(max--);
		}
	}
	ans.push_back(min);

	return ans;
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A) {
	vector<int> ans;
	long sum = -1;
	int index = A.size();

	for(int i = 0; i < A.size(); ++i) {
		if(A[i] >= 0) {
			vector<int> tmp;
			long tsum = 0;

			int j = i;
			while(j < A.size() && A[j] >= 0) {
				tmp.push_back(A[j]);
				tsum += A[j];
				++j;
			}

			if(tsum > sum) {
				sum = tsum;
				ans = tmp;
				index = i;
			}
			else if(tsum == sum && tmp.size() > ans.size()) {
				sum = tsum;
				ans = tmp;
				index = i;
			}
			else if(i < index) {
				sum = tsum;
				ans = tmp;
				index = i;
			}

			i = j;
		}
	}

	return ans;
}

int main(void) {
	vector<int> a {336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421};

	for(int i: maxset(a)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
	int carry = 1;
	vector<int> ans;

	int end = 0;
	while(A[end] == 0) {
		end++;
	}
	end--;

	for(int i = A.size() - 1; i > end; --i) {
		int sum = A[i] + carry;

		ans.push_back(sum % 10);
		carry = sum / 10;
	}
	while(carry) {
		ans.push_back(carry % 10);
		carry /= 10;
	}

	vector<int> final_ans;
	for(int i = ans.size() - 1; i >= 0; --i) {
		final_ans.push_back(ans[i]);
	}

	return final_ans;
}

int main(void) {
	vector<int> a {0};

	for(int i: plusOne(a)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
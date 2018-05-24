#include <bits/stdc++.h>
using namespace std;

string largestNumber(const vector<int> &A) {
	vector<string> nums;
	for(int i: A) {
		nums.push_back(to_string(i));
	}

	sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
		return a + b > b + a;
	});

	string ans;
	for(int i = 0; i < nums.size(); ++i) {
		ans += nums[i];
	}

	int i = 0;
	while(ans[i] == '0') {
		++i;
	}

	if(i == ans.size()) {
		return "0";
	}

	return ans;
}

int main(void) {
	vector<int> a {3, 30, 34, 5, 9};
	cout << largestNumber(a) << endl;

	return 0;
}
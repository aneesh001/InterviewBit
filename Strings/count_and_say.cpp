#include <bits/stdc++.h>
using namespace std;

string countAndSay(int A) {
	vector<int> num(1, 1);
	int n = 1;

	while(n < A) {
		vector<int> new_num;

		int i = 0;
		while(i < num.size()) {
			int to_put = num[i];
			int count = 1;

			++i;

			while(i < num.size() && num[i] == to_put) {
				++count;
				++i;
			}

			new_num.push_back(count);
			new_num.push_back(to_put);
		}

		num = new_num;
		++n;
	}

	string ans;
	for(int i = 0; i < num.size(); ++i) {
		ans += to_string(num[i]);
	}

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	cout << countAndSay(n) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string A) {
	map<char, int> value;
	value.insert({'I', 1});
	value.insert({'V', 5});
	value.insert({'X', 10});
	value.insert({'L', 50});
	value.insert({'C', 100});
	value.insert({'D', 500});
	value.insert({'M', 1000});

	int ans = 0;
	for(int i = 0; i < A.size(); ++i) {
		int val1 = value[A[i]];

		if(i + 1 < A.size()) {
			int val2 = value[A[i + 1]];

			if(val1 >= val2) {
				ans += val1;
			}
			else {
				ans += val2 - val1;
				++i;
			}
		}
		else {
			ans += val1;
		}
	}

	return ans;
}

int main(void) {

}
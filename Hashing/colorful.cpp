#include <bits/stdc++.h>
using namespace std;

int colorful(int A) {
	vector<int> digits;
	while(A) {
		digits.push_back(A % 10);
		A /= 10;
	}
	
	reverse(digits.begin(), digits.end());
	
	unordered_set<int> seen;
	for(int i = 0; i < digits.size(); ++i) {
		int prd = 1;
		for(int j = i; j < digits.size(); ++j) {
			prd *= digits[j];
			
			if(seen.find(prd) != seen.end()) {
				return 0;
			}
			else {
				seen.insert(prd);
			}
		}
	}
	
	return 1;
}

int main(void) {
	
}
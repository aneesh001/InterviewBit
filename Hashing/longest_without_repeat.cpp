#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string A) {
	unordered_set<char> seen;
	int i = 0, j = 0;
	int ans = 1;
	
	while(i < A.size() && j < A.size()) {
		if(seen.find(A[j]) == seen.end()) {
			seen.insert(A[j]);
			j++;
			ans = max(ans, j - i);
		}
		else {
			seen.erase(A[i]);
			i++;
		}
	}
	
	return ans;
}

int main(void) {
	return 0;
}
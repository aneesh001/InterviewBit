#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int B) {
	unordered_map<int, int> cnt;
	for(int i = 0; i < A.size(); ++i) {
		cnt[A[i]]++;
	}
	
	decltype(cnt.begin()) it;
	for(int i = 0; i < n; ++i) {
		int tf = A[i] - B;
		
		it = cnt.find(tf);
		
		if(it != cnt.end()) {
			if(A[i] == to_find && it->second > 1) {
				return 1;
			}
			else if(A[i] != to_find) {
				return 1;
			}
		}
	}
	
	return 0;
}

int main(void) {
	
}
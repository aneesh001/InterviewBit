#include <bits/stdc++.h>
using namespace std;

vector<int> lszero(vector<int> &A) {
	int ans_idx = 0;
	int ans_len = 0;
	unordered_map<int, int> seen;
	
	int sum = 0;
	decltype(seen.begin()) it;
	for(int i = 0; i < A.size(); ++i) {
		sum += A[i];
		
		if(sum == 0 && i + 1 > ans_len) {
			ans_len = i + 1;
			ans_idx = 0;
		}
		else if((it = seen.find(sum)) != seen.end() && i - it->second + 1 > ans_len) {
			ans_len = i - it->second + 1;
			ans_idx = it->second;
		}
		else if((it = seen.find(sum)) == seen.end()){
			seen[sum] = i;
		}
	}
	
	vector<int> ans;
	for(int i = ans_idx; i < ans_idx + ans_len; ++i) {
		ans.push_back(A[i]);
	}
	
	return ans;
}

int main(void) {
	return 0;
}
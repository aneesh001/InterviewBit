#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &A, int B) {
	sort(A.begin(), A.end());
    
	set<vector<int>> ans;
	for(int i = 0; i < A.size(); ++i) {
	    for(int j = i + 1; j < A.size(); ++j) {
	        for(int k = j + 1; k < A.size(); ++k) {
	            for(int l = k + 1; l < A.size(); ++l) {
	                if(A[i] + A[j] + A[k] + A[l] == B) {
	                    ans.insert(vector<int>{A[i], A[j], A[k], A[l]});
	                }
	            }
	        }
	    }
	}
    
	return vector<vector<int>>(ans.begin(), ans.end());
}

// Much better to do loop over 2 and then do 2 sum inside. This will be O(n^3).
int main(void) {
	return 0;
}
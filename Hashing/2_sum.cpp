#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {
	unordered_map<int, vector<int>> mp;
	    for(int i = 0; i < A.size(); ++i) {
	        mp[A[i]].push_back(i);
	    }
    
	    decltype(mp.begin()) it;
	    vector<pair<int, int>> ans;
	    for(int i = 0; i < A.size(); ++i) {
	        it = mp.find(B - A[i]);
        
	        if(it != mp.end()) {
	            if(2 * A[i] == B && it->second.size() > 1) {
	                int minm = min(it->second[0] + 1, it->second[1] + 1);
	                int maxm = max(it->second[0] + 1, it->second[1] + 1);
	                ans.push_back({minm, maxm});
	            }
	            else if(A[i] != B - A[i]) {
	                int minm = min(it->second[0] + 1, i + 1);
	                int maxm = max(it->second[0] + 1, i + 1);
	                ans.push_back({minm, maxm});
	            }
	        }
	    }
    
	    if(ans.size() == 0) {
	        return vector<int>();
	    }
    
	    sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
	        if(a.second != b.second) {
	            return a.second < b.second;
	        }
	        else {
	            return a.first < b.first;
	        }
	    });
    
	    return vector<int> {ans[0].first, ans[0].second};
}

int main(void) {
	
}
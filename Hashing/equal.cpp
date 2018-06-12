#include <bits/stdc++.h>
using namespace std;

vector<int> equal(vector<int> &A) {
	unordered_map<int, pair<int, int>> mp;
	    decltype(mp.begin()) it;
    
	    vector<vector<int>> ans;
    
	    for(int i = 0; i < A.size(); ++i) {
	        for(int j = i + 1; j < A.size(); ++j) {
	            int s = A[i] + A[j];
            
	            it = mp.find(s);
            
	            if(it == mp.end()) {
	                mp.insert({s, {i, j}});
	            }
	            else {
	                int oi = it->second.first;
	                int oj = it->second.second;
                
	                if(i != oi && i != oj && j != oi && j != oj) {
	                    ans.push_back(vector<int>{oi, oj, i, j});
	                }
	            }
	        }
	    }
    
	    if(ans.size() == 0) {
	        return vector<int>();
	    }
    
	    sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b) {
	        for(int i = 0; i < 4; ++i) {
	            if(a[i] != b[i]) {
	                return a[i] < b[i];
	            }
	        }
        
	        return a[0] < b[0];
	    });
    
	    return ans[0];
}

int main(void) {
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	for(int i: equal(arr)) {
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
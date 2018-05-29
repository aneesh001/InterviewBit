#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {
    map<int, int> count;

    for(int i = 0; i < A.size(); ++i) {
    	if(count.size() < 3) {
    		count[A[i]] += 1;
    	}
    	else if(count.size() >= 3 && count.find(A[i]) != count.end()) {
    		count[A[i]] += 1;
    	}
    	else {
    		set<int> to_remove;
    		for(auto it = count.begin(); it != count.end(); ++it) {
    			it->second -= 1;

    			if(it->second == 0) {
    				to_remove.insert(it->first);
    			}
    		}

    		for(int i: to_remove) {
    			count.erase(i);
    		}
    	}
    }

    for(auto it = count.begin(); it != count.end(); ++it) {
    	int c = 0;
    	for(int i = 0; i < A.size(); ++i) {
    		if(A[i] == it->first) {
    			++c;
    		}
    	}

    	if(c >= A.size() / 3) {
    		return it->first;
    	}
    }

    return -1;
}

int main(void) {
	vector<int> arr(455, 0);
	for(int i = 0; i < 455; ++i) {
		cin >> arr[i];
	}

	cout << repeatedNumber(arr) << endl;
	return 0;
}
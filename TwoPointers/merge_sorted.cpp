#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    vector<int> ans;

    int i = 0;
    int j = 0;
    int k = 0;
    for(; k < A.size() + B.size(); ++k) {
    	if(i >= A.size()) {
    		ans.push_back(B[j++]);
    	}
    	else if(j >= B.size()) {
    		ans.push_back(A[i++]);
    	}
    	else if(A[i] < B[j]) {
    		ans.push_back(A[i++]);
    	}
    	else {
    		ans.push_back(B[j++]);
    	}
    }

    A = ans;
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    set<int> rows;
    set<int> cols;

    for(int i = 0; i < A.size(); ++i) {
    	for(int j = 0; j < A[i].size(); ++j) {
    		if(A[i][j] == 0) {
    			rows.insert(i);
    			cols.insert(j);
    		}
    	}
    }

    for(int i: rows) {
    	for(int j = 0; j < A[i].size(); ++j) {
    		A[i][j] = 0;
    	}
    }

    for(int i: cols) {
    	for(int j = 0; j < A.size(); ++j) {
    		A[j][i] = 0;
    	}
    }
}

int main(void) {

}
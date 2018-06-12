#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> anagrams(const vector<string> &A) {
	int count[A.size()][27];
	for(int i = 0; i < A.size(); ++i) {
		for(int j = 0; j < 27; ++j) {
			count[i][j] = 0;
		}
	}
	
	for(int i = 0; i < A.size(): ++i) {
		for(char ch: A[i]) {
			count[i][ch - 'a']++;
		}
	}
	
	vector<vector<int>> ans;
	vector<bool> checked(A.size(), false);
	
	for(int i = 0; i < A.size(); ++i) {
		if(!checked[i]) {
			vector<int> c;
			c.push_back(i + 1);
			checked[i] = true;
			
			for(int j = i + 1; j < A.size(); ++j) {
				bool flag = true;
				for(int k = 0; k < 27; ++k) {
					if(count[i][k] != count[j][k]) {
						flag = false;
						break;
					}
				}
				
				if(flag) {
					c.push_back(j + 1);
					checked[j] = true;
				}
			}
			
			ans.push_back(c);
		}
	}
	
	return ans;
}

int main(void) {
	return 0;
}
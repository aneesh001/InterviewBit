#include <bits/stdc++.h>
using namespace std;

#define MOD 1003

vector<vector<int>> tdp;
vector<vector<int>> fdp;

int ways(const string &s, int i, int j, int v) {
    if(v == 1) {
        if(tdp[i][j] != -1) {
            return tdp[i][j];
        }

        if(i == j && s[i] == 'T') {
            return 1;
        }
        else if(i == j){
            return 0;
        }

        int ans = 0;
        int op = i;
        while(op <= j) {
            while(op <= j && (s[op] == 'T' || s[op] == 'F')) {
                ++op;
            }

            if(op > j) break;

            if(s[op] == '|') {
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 0)) % MOD;
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 1)) % MOD;
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 1)) % MOD;
            }
            else if(s[op] == '&') {
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 1)) % MOD;
            }
            else {
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 0)) % MOD;
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 1)) % MOD;
            }
            
            ++op;
        }

        tdp[i][j] = ans;
        return ans;
    }
    else {
        if(fdp[i][j] != -1) {
            return fdp[i][j];
        }

        if(i == j && s[i] == 'F') {
            return 1;
        }
        else if(i == j){
            return 0;
        }

        int ans = 0;
        int op = i;
        while(op <= j) {
            while(op <= j && (s[op] == 'T' || s[op] == 'F')) {
                ++op;
            }

            if(op > j) break;

            if(s[op] == '|') {
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 0)) % MOD;
            }
            else if(s[op] == '&') {
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 0)) % MOD;
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 1)) % MOD;
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 0)) % MOD;
            }
            else {
                ans = (ans + ways(s, i, op - 1, 1) * ways(s, op + 1, j, 1)) % MOD;
                ans = (ans + ways(s, i, op - 1, 0) * ways(s, op + 1, j, 0)) % MOD;
            }
            
            ++op;
        }

        fdp[i][j] = ans;
        return ans;
    }
}

int cnttrue(string A) {
	tdp = vector<vector<int>>(A.size(), vector<int>(A.size(), -1));
	fdp = vector<vector<int>>(A.size(), vector<int>(A.size(), -1));
	return ways(A, 0, A.size() - 1, 1);
}

int main(void) {
	string s;
	cin >> s;

	cout << cnttrue(s) << endl;
	return 0;
}
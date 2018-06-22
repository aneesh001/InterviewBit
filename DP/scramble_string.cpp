#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, bool> dp;
int util(const string &a, const string &b) {

    pair<string, string> cur = make_pair(a, b);
    if (dp.find(cur) != dp.end()) return dp[cur];
    
    unordered_map<char, int> count;
    for(char c: a) {
        count[c]++;
    }
    for(char c: b) {
        count[c]--;
    }

    for(auto &p: count) {
        if(p.second != 0) return dp[cur] = false;
    }
    
    if(a.size() <= 2) return dp[cur] = true;
    
    for(int i = 1; i < a.length(); i++) {
        if(util(a.substr(0, i), b.substr(0, i))
            && util(a.substr(i), b.substr(i))) return dp[cur] = true;
        if(util(a.substr(0, i), b.substr(b.length() - i)) 
            && util(a.substr(i), b.substr(0, b.length() - i))) return dp[cur] = true;
    }
    return dp[cur] = false;
}

int isScramble(const string A, const string B) {
	dp.clear();
	int i = A.size() - 1;
	int j = B.size() - 1;
	while(i >= 0 && !isalpha(A[i])) --i;
	while(j >= 0 && !isalpha(B[j])) --j;
	assert(i == j);

	return util(A.substr(0, i + 1), B.substr(0, j + 1));
}

int main(void) {
	string a, b;
	cin >> a >> b;
	assert(a.size() == b.size());

	cout << isScramble(a, b) << endl;
	return 0;
}
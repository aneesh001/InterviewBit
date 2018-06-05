#include <bits/stdc++.h>
using namespace std;

string convert(string A, int B) {
	if(B >= A.size() || B == 1) {
        return A;
    }
    
    vector<string> rows(B);

    int r = 0;
    int inc = 1;
    for(int i = 0; i < A.size(); ++i) {
        rows[r] += A[i];
        
        if(r + inc < 0 || r + inc >= B) {
            inc = (inc == 1) ? -1 : 1;
        }
        
        r += inc;
    }

    string ans;
    for(string &a: rows) {
        ans += a;
    }

    return ans;
}

int main(void) {
	string s;
	int n;

	cin >> s >> n;

	cout << convert(s, n) << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> util(int i) {
	vector<string> ans;

	if(i <= 0) {
		ans.push_back("0");
		return ans;
	}

	vector<string> others = util(i - 1);
	for(int j = 0; j < others.size(); ++j) {
		ans.push_back("0" + others[j]);
	}
	for(int j = others.size() - 1; j >= 0; --j) {
		ans.push_back("1" + others[j]);
	}

	return ans;
}

vector<int> grayCode(int A) {
    vector<string> ans = util(A);

    vector<int> code;
    for(int i = 0; i < ans.size(); ++i) {
    	int a = 0;
    	for(int j = ans[i].size() - 1; j >= 0; --j) {
    		a = (2 * a) + (ans[i][j] - '0');
    	}
    	code.push_back(a);
    }

    return code;
}

int main(void) {
	int n;
	cin >> n;

	for(int i: grayCode(n)) {
		cout << i << endl;
	}

	return 0;
}
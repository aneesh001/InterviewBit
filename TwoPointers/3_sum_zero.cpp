#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &A) {
	vector<vector<int>> ans;

    sort(A.begin(), A.end());

    int i = 0;
    while(i < A.size()) {
        int to_find = 0 - A[i];

        int j = i + 1;
        int k = A.size() - 1;

        while(j < k) {
            int s = A[j] + A[k];

            if(s == to_find) {
                a.insert(vector<int>{A[i], A[j], A[k]});
                ++j;
                --k;
            }
            else if(s < to_find) {
                ++j;
            }
            else {
                --k;
            }
        }

        ++i;
    }
    
    for(auto &v: a) {
        ans.push_back(v);
    }

    return ans;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for(auto &v: threeSum(arr)) {
		for(int i: v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
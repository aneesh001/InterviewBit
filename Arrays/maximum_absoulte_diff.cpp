#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
   	int max1 = INT_MIN, min1 = INT_MAX;
   	for(int i = 0; i < A.size(); ++i) {
   		max1 = max(max1, A[i] + i);
   		min1 = min(min1, A[i] + i);
   	}
   	int ans = max1 - min1;
   	max1 = INT_MIN, min1 = INT_MAX;
   	for(int i = 0; i < A.size(); ++i) {
   		max1 = max(max1, A[i] - i);
   		min1 = min(min1, A[i] - i);
   	}
   	ans = max(ans, max1 - min1);

   	return ans;
}

int main(void) {
	vector<int> a {1, 3, -1};

	cout << maxArr(a) << endl;

	return 0;
}
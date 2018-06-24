#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &A) {
    int n = A.size();
    vector<int> candy(n, 1);
    for(int i = 1; i < n; ++i) {
        if(A[i] > A[i - 1] && candy[i] <= candy[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; --i) {
        if(A[i] > A[i + 1] && candy[i] <= candy[i + 1]) {
            candy[i] = candy[i + 1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += candy[i];
    }
    return ans;
}

int main(void) {
    return 0;
}

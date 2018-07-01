#include <bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int> &A) {
    int n = A.size();
    vector<int> pos(n + 1, 0);
    vector<int> neg(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        int cur = A[i - 1];

        if(cur > 0) {
            pos[i] = max(pos[i - 1] * cur, cur);
            neg[i] = min(neg[i - 1] * cur, cur);
        }
        else {
            pos[i] = max(neg[i - 1] * cur, cur);
            neg[i] = min(pos[i - 1] * cur, cur);
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i <= n; ++i) {
        ans = max(ans, max(pos[i], neg[i]));
    }

    return ans;
}

int main(void) {
    return 0;
}

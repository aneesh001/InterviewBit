#include <bits/stdc++.h>
using namespace std;

#define MOD 1000007

int coinchange2(vector<int> &A, int B) {
    if(B == 0) return 1;
    else if(A.size() == 0) return 0;

    vector<int> prev(B + 1, 0);
    prev[0] = 1;

    for(int i = 1; i <= A.size(); ++i) {
        int cur = A[i - 1];
        vector<int> next(B + 1, 0);
        next[0] = 1;
        for(int j = 1; j <= B; ++j) {
            if(j - cur >= 0) {
                next[j] = (next[j] + next[j - cur]) % MOD;
            }
            next[j] = (next[j] + prev[j]) % MOD;
        }

        swap(prev, next);
    }

    return prev[B];
}

int main(void) {
    return 0;
}

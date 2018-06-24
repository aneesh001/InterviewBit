#include <bits/stdc++.h>
using namespace std;

int maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());

    int p = A[n - 1] * A[n - 2] * A[n - 3];
    p = max(p, A[0] * A[1] * A[2]);
    p = max(p, A[0] * A[1] * A[n - 1]);
    p = max(p, A[0] * A[n - 1] * A[n - 2]);

    return p;
}

int main(void) {
    return 0;
}

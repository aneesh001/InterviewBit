#include <bits/stdc++.h>
using namespace std;

int bulbs(vector<int> &A) {
    int on = 1;
    int ans = 0;

    for(int i = 0; i < A.size(); ++i) {
        if(A[i] != on) {
            ans++;
            on = (on == 1) ? 0 : 1;
        }
    }

    return ans;
}

int main(void) {
    return 0;
}

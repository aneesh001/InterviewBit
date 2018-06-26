#include <bits/stdc++.h>
using namespace std;

#define MAX 50
#define ll long long
ll fibs[MAX];

void precompute() {
    fibs[0] = 0;
    fibs[1] = 1;
    for(int i = 2; i < MAX; ++i) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
}

int fibsum(int A) {
    precompute();

    int i = -1;
    while(i + 1 < MAX && fibs[i + 1] <= A) ++i;

    if(i == -1) return -1;

    int taken = 0;
    ll sum = 0;
    while(sum != A && i >= 0) {
        if(fibs[i] + sum <= A) {
            sum += fibs[i];
            ++taken;
        }
        else {
            --i;
        }
    }

    return taken;
}

int main(void) {
    int a;
    cin >> a;

    cout << fibsum(a) << endl;
    return 0;
}

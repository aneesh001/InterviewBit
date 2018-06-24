#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int pending = 0;
    int start = 0;
    int petrol = 0;

    for(int i = 0; i < n; ++i) {
        petrol += (A[i] - B[i]);

        if(petrol < 0) {
            int j = ans;
            while(petrol < 0 && j <= i) {
                petrol -= A[j] - B[j];
                pending += A[j] - B[j];
                ++j;
            }

            ans = j;
        }
    }

    if(ans >= n || petrol + pending < 0) return -1;
    else return ans;
}

int main(void) {
    return 0;
}

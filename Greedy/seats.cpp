#include <bits/stdc++.h>
using namespace std;

#define MOD 10000003

int seats(string A) {
    int first = 0;
    while(first < A.size() && A[first] == '.') first++;
    int last = A.size() - 1;
    while(last >= 0 && A[last] == '.') last--;

    vector<int> pos;
    for(int i = first; i <= last; ++i) {
        if(A[i] == 'x') {
            pos.push_back(i);
        }
    }

    int n = pos.size();
    if(n == 0) return 0;

    if(n % 2 != 0) {
        vector<int> ideal_pos;
        int mid = pos[n / 2];
        ideal_pos.push_back(mid);
        int low = mid - 1;
        int high = mid + 1;
        int taken = 1;

        while(taken < n) {
            ideal_pos.push_back(low--);
            ideal_pos.push_back(high++);
            taken += 2;
        }

        sort(ideal_pos.begin(), ideal_pos.end());

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = (ans + abs(pos[i] - ideal_pos[i])) % MOD;
        }

        return ans;
    }
    else {
        int mid = (pos[n / 2] + pos[n / 2 - 1]) / 2;
        vector<int> ideal_pos;
        ideal_pos.push_back(mid);
        int low = mid - 1, high = mid + 1, taken = 0;
        while(taken < n) {
            ideal_pos.push_back(low--);
            ideal_pos.push_back(high++);
            taken += 2;
        }

        sort(ideal_pos.begin(), ideal_pos.end());

        int ans = INT_MAX;
        if(ideal_pos[0] >= 0) {
            int ans1 = 0;
            for(int i = 0; i < n; ++i) {
                ans1 = (ans1 + abs(pos[i] - ideal_pos[i])) % MOD;
            }
            ans = min(ans, ans1);
        }

        if(ideal_pos[n - 1] <= pos[n - 1]) {
            int ans1 = 0;
            for(int i = 1; i <= n; ++i) {
                ans1 = (ans1 + abs(pos[i - 1] - ideal_pos[i])) % MOD;
            }
            ans = min(ans, ans1);
        }

        return ans;
    }
}

int main(void) {
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &A) {
    int n = A.size();

    map<int, int> count;
    count[A[i]]++;
    for(int i = 1; i < n; ++i) {
        auto it = count.find(A[i]);

        if(it != count.end()) count[A[i]]++;
        else {
            int least = count.begin()->first;
            for(auto &p: count) {
                if(p.second < count[least]) {
                    least = p.first;
                }
            }

            count.erase(min);
            count[A[i]]++;
        }
    }

    int ans = count.begin()->first;
    for(auto &p: count) {
        if(p.second > count[ans]) {
            ans = p.first;
        }
    }

    return ans;
}

int main(void) {
    return 0;
}

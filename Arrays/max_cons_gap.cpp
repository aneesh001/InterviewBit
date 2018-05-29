#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
	if(A.size() < 2) return 0;
    
    vector<int> sorted(A);
    sort(sorted.begin(), sorted.end());
    
    int ans = INT_MIN;
    for(int i = 0; i < A.size() - 1; ++i) {
        ans = max(ans, sorted[i + 1] - sorted[i]);
    }
    
    return ans;
}

int main(void) {

}
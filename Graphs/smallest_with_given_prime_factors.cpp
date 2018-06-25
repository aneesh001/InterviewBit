#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int A, int B, int C, int D) {
    unordered_set<int> primes{A, B, C};
    vector<int> ans;
    unordered_set<int> vis {primes.begin(), primes.end()};
    priority_queue<int, vector<int>, greater<int>> q {primes.begin(), primes.end()};

    while(ans.size() != D) {
        int front = q.top();
        q.pop();

        ans.push_back(front);

        for(int i: primes) {
            if(vis.find(i * front) == vis.end()) {
                vis.insert(i * front);
                q.push(i * front);
            }
        }
    }

    return ans;
}

int main(void) {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    for(int i: solve(a, b, c, k)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

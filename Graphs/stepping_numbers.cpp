#include <bits/stdc++.h>
using namespace std;

vector<int> stepnum(int A, int B) {
    unordered_set<int> vis;
    vis.insert(1);

    queue<int> q;
    for(int i = 1; i < 10; ++i) {
        q.push(i);
    }

    vector<int> ans;

    while(!q.empty()) {
        int top = q.front();
        q.pop();

        if(top >= A && top <= B) {
            ans.push_back(top);
        }

        int last1 = top % 10 + 1;
        int last2 = top % 10 - 1;
        int num1 = top * 10 + last1;
        int num2 = top * 10 + last2;

        if(last1 <= 9 && num1 <= B && vis.find(num1) == vis.end()) {
            vis.insert(num1);
            q.push(num1);
        }
        if(last2 >= 0 && num2 <= B && vis.find(num2) == vis.end()) {
            vis.insert(num2);
            q.push(num2);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for(int i: stepnum(n, m)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

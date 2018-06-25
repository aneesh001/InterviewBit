#include <bits/stdc++.h>
using namespace std;

struct node {
    int last_digit;
    int mod_val;
    node *parent;

    node(int ld, int mv, node *p) {
        last_digit = ld;
        mod_val = mv;
        parent = p;
    }
};

// Runs out of memory. Instead use vectors. The logic is correct tho.
string multiple(int A) {
    if(A == 0) return "";

    vector<int> vis(A, false);
    vis[1 % A] = true;

    queue<node*> q;
    q.push(new node(1, 1 % A, nullptr));

    while(!q.empty()) {
        node *top = q.front();
        q.pop();

        if(top->mod_val == 0) {
            string ans;
            while(top != nullptr) {
                ans += static_cast<char>(top->last_digit + '0');
                top = top->parent;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        else {
            int v = (top->mod_val * 10) % A;
            if(!vis[v]) {
                vis[v] = true;
                q.push(new node(0, v, top));
            }
            v = (v + 1) % A;
            if(!vis[v]) {
                vis[v] = true;
                q.push(new node(1, v, top));
            }
        }
    }

    return "";
}

int main(void) {
    int n;
    cin >> n;

    cout << multiple(n) << endl;
    return 0;
}

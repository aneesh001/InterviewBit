#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &g, vector<int> &ft, vector<bool> &vis, int &t) {
    vis[src] = true;
    for(int i: g[src]) {
        if(!vis[i]) {
            dfs(i, g, ft, vis, t);
        }
    }
    ft[src] = t;
    ++t;
}

int solve(int n, vector<int> &B, vector<int> &C) {
    vector<vector<int>> graph(n, vector<int>());
    for(int i = 0; i < B.size(); ++i) {
        int u = B[i] - 1;
        int v = C[i] - 1;
        graph[u].push_back(v);
    }

    vector<int> ft(n, -1);
    vector<bool> vis(n, false);
    int t = 0;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            dfs(i, graph, ft, vis, t);
        }
    }

    for(int i = 0; i < B.size(); ++i) {
        int u = B[i] - 1;
        int v = C[i] - 1;

        if(ft[u] < ft[v]) return 0;
    }

    return 1;
}

int main(void) {
    return 0;
}

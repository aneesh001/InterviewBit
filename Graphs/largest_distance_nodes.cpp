#include <bits/stdc++.h>
using namespace std;

// Better method(in terms of memory):
// 1. From any node find the farthest node. Call it s.
// 2. From s find the farthest node. Call it t.
// 3. Ans is distance between s and t.
// Actually even this method can be implemented without extra memory.
void dfs(int src, vector<vector<int>> &g, vector<bool> &vis, vector<int> &depth) {
    vis[src] = true;
    int ans = 0;
    for(int i: g[src]) {
        if(!vis[i]) {
            dfs(i, g, vis, depth);
            ans = max(ans, 1 + depth[i]);
        }
    }
    depth[src] = ans;
}

int util(int src, vector<vector<int>> &g, vector<bool> &vis, vector<int> &depth) {
    vis[src] = true;
    int child_max = 0;
    vector<int> child_depths;
    for(int i: g[src]) {
        if(!vis[i]) {
            int child_ans = util(i, g, vis, depth);
            child_max = max(child_ans, child_max);
            child_depths.push_back(depth[i]);
        }
    }
    sort(child_depths.begin(), child_depths.end());

    int c = 0;
    int other = 0;
    if((int)child_depths.size() - 1 >= 0) {
        other += child_depths[child_depths.size() - 1];
        c++;
    }
    if((int)child_depths.size() - 2 >= 0) {
        other += child_depths[child_depths.size() - 2];
        c++;
    }

    if(c == 0) {
        return 0;
    }
    else if(c == 1) {
        return max(1 + other, child_max);
    }
    else {
        return max(2 + other, child_max);
    }
}

int solve(vector<int> &A) {
    int n = A.size();

    vector<vector<int>> graph(n, vector<int>());
    vector<bool> vis(n, false);
    int root;
    for(int i = 0; i < n; ++i) {
        int u = i;
        int v = A[i];

        if(v == -1) {
            root = i;
        }
        else {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    vector<int> depth(n, -1);
    dfs(root, graph, vis, depth);

    fill(vis.begin(), vis.end(), false);
    return util(root, graph, vis, depth);
}

int main(void) {
    return 0;
}

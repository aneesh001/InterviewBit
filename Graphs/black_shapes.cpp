#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int si, int sj, vector<string> &g, vector<vector<bool>> &vis) {
    int n = g.size();
    int m = g[0].size();
    vis[si][sj] = true;
    int ni, nj;

    ni = si + 1; nj = sj;
    if(valid(ni, nj, n, m) && g[ni][nj] == 'X' && !vis[ni][nj]) {
        dfs(ni, nj, g, vis);
    }
    ni = si - 1; nj = sj;
    if(valid(ni, nj, n, m) && g[ni][nj] == 'X' && !vis[ni][nj]) {
        dfs(ni, nj, g, vis);
    }
    ni = si; nj = sj + 1;
    if(valid(ni, nj, n, m) && g[ni][nj] == 'X' && !vis[ni][nj]) {
        dfs(ni, nj, g, vis);
    }
    ni = si; nj = sj - 1;
    if(valid(ni, nj, n, m) && g[ni][nj] == 'X' && !vis[ni][nj]) {
        dfs(ni, nj, g, vis);
    }
}

int black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vis[i][j] && A[i][j] == 'X') {
                dfs(i, j, A, vis);
                ++ans;
            }
        }
    }

    return ans;
}

int main(void) {
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

vector<int> ni = {1, -1, 0, 0};
vector<int> nj = {0, 0, 1, -1};

void solve(vector<vector<char>> &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    for(int i = 0; i < m; ++i) {
        if(A[0][i] == 'O') {
            q.push({0, i});
            vis[0][i] = true;
        }
    }
    for(int i = 1; i < n - 1; ++i) {
        if(A[i][m - 1] == 'O') {
            q.push({i, m - 1});
            vis[i][m - 1] = true;
        }
    }
    for(int i = 0; i < m; ++i) {
        if(A[n - 1][i] == 'O') {
            q.push({n - 1, i});
            vis[n - 1][i] = true;
        }
    }
    for(int i = 1; i < n - 1; ++i) {
        if(A[i][0] == 'O') {
            q.push({i, 0});
            vis[i][0] = true;
        }
    }

    while(!q.empty()) {
        int ti = q.front().first;
        int tj = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int pi = ti + ni[i];
            int pj = tj + nj[i];
            if(valid(pi, pj, n, m) && !vis[pi][pj] && A[pi][pj] == 'O') {
                vis[pi][pj] = true;
                q.push({pi, pj});
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vis[i][j] && A[i][j] == 'O') {
                A[i][j] = 'X';
            }
        }
    }
}

int main(void) {
    return 0;
}

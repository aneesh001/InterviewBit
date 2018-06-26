#include <bits/stdc++.h>
using namespace std;

bool is_valid(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int knight(int n, int m, int si, int sj, int di, int dj) {
    si--; sj--;
    di--; dj--;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;

    while(!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        int ni, nj;

        ni = ci - 2; nj = cj - 1;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci - 2; nj = cj + 1;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci - 1; nj = cj + 2;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci + 1; nj = cj + 2;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci + 2; nj = cj + 1;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci + 2; nj = cj - 1;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci + 1; nj = cj - 2;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }

        ni = ci - 1; nj = cj - 2;
        if(is_valid(ni, nj, n, m) && !vis[ni][nj]) {
            vis[ni][nj] = true;
            dist[ni][nj] = dist[ci][cj] + 1;
            q.push({ni, nj});
        }
    }

    return dist[di][dj];
}

int main(void) {
    return 0;
}

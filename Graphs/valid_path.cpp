#include <bits/stdc++.h>
using namespace std;

vector<int> nx {-1, +1, -1, +0, +1, -1, +0, +1};
vector<int> ny {+0, +0, +1, +1, +1, -1, -1, -1};

bool touches_circle(int x, int y, int r, vector<int> &cx, vector<int> &cy) {
    for(int i = 0; i < cx.size(); ++i) {
        int a = x - cx[i];
        int b = y - cy[i];

        if(a * a + b * b <= r * r) return true;
    }

    return false;
}

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

string solve(int x, int y, int n, int r, vector<int> &cx, vector<int> &cy) {
    vector<vector<int>> vis(x + 1, vector<int>(y + 1, false));
    vis[0][0] = true;

    queue<pair<int, int>> q;
    q.push({0, 0});

    if(x == 0 && y == 0) return "YES";

    while(!q.empty()) {
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();

        for(int i = 0; i < 8; ++i) {
            int px = sx + nx[i];
            int py = sy + ny[i];

            if(valid(px, py, x, y) && !vis[px][py] &&
            !touches_circle(px, py, r, cx, cy)) {

                q.push({px, py});
                vis[px][py] = true;
            }
        }
    }

    if(vis[x][y]) return "YES";
    else return "NO";
}

int main(void) {
    return 0;
}

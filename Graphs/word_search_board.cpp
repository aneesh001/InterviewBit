#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ni = {1, -1, 0, 0};
vector<int> nj = {0, 0, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(int si, int sj, int i, vector<string> &g, string &src) {
    assert(i < src.size());
    if(i + 1 == src.size()) return true;

    for(int j = 0; j < 4; ++j) {
        int pi = si + ni[j];
        int pj = sj + nj[j];
        if(valid(pi, pj) && g[pi][pj] == src[i + 1] && dfs(pi, pj, i + 1, g, src)) {
            return true;
        }
    }

    return false;
}

int exist(vector<string> &A, string B) {
    n = A.size();
    m = A[0].size();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(A[i][j] == B[0] && dfs(i, j, 0, A, B)) {
                return 1;
            }
        }
    }

    return 0;
}

int main(void) {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string key;
    cin >> key;

    cout << exist(words, key) << endl;
    return 0;
}

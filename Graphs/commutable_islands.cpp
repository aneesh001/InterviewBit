#include <bits/stdc++.h>
using namespace std;

class union_find {
private:
    int components;
    vector<int> rank;
    vector<int> parent;

public:
    union_find(int n) {
        components = n;
        for(int i = 0; i < n; ++i) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int count() { return components; }

    int find(int i) {
        if(parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        if(pi == pj) return;

        if(rank[pi] < rank[pj]) {
            parent[pi] = pj;
        }
        else {
            parent[pj] = pi;

            if(rank[pi] == rank[pj]) {
                rank[pi]++;
            }
        }

        --components;
    }
};

int solve(int A, vector<vector<int>> &B) {
    sort(B.begin(), B.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    });

    union_find uf(A);

    int i = 0;
    int cost = 0;
    while(uf.count() > 1) {
        int u = B[i][0] - 1;
        int v = B[i][1] - 1;
        int c = B[i][2];

        if(!uf.connected(u, v)) {
            uf.merge(u, v);
            cost += c;
        }

        ++i;
    }

    return cost;
}

int main(void) {
    return 0;
}

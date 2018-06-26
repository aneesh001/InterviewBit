#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> d;
    unordered_map<int, vector<int>> tree;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(int src, int dst) {
        path.push_back(d[src]);

        if(src == dst) {
            ans.push_back(path);
            reverse(ans[ans.size() - 1].begin(), ans[ans.size() - 1].end());
        }
        else {
            for(int i: tree[src]) {
                dfs(i, dst);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string start, string end, vector<string> &dict) {
        unordered_set<string> uniques { dict.begin(), dict.end() };
        uniques.insert(start);
        uniques.insert(end);

        d = { uniques.begin(), uniques.end() };
        int n = d.size();
        mp.clear();
        for(int i = 0; i < n; ++i) {
            mp[d[i]] = i;
        }

        queue<int> q; q.push(mp[start]);
        vector<bool> vis(n, false); vis[mp[start]] = true;
        vector<int> level(n, -1); level[mp[start]] = 0;
        tree.clear();
        for(int i = 0; i < n; ++i) tree.insert({i, vector<int>()});

        while(!q.empty()) {
            int idx = q.front();
            string top = d[idx];
            q.pop();

            for(int i = 0; i < top.size(); ++i) {
                char tmp = top[i];
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    top[i] = ch;

                    if(mp.find(top) != mp.end() && !vis[mp[top]]) {
                        vis[mp[top]] = true;
                        q.push(mp[top]);
                        level[mp[top]] = level[idx] + 1;
                        tree[mp[top]].push_back(idx);
                    }
                    else if(mp.find(top) != mp.end() && level[mp[top]] > level[idx]) {
                        tree[mp[top]].push_back(idx);
                    }
                }
                top[i] = tmp;
            }
        }

        ans.clear(); path.clear();
        dfs(mp[end], mp[start]);

        return ans;
    }
};

int main(void) {
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string src, dst;
    cin >> src >> dst;

    Solution solver;

    for(auto &vs: solver.findLadders(src, dst, words)) {
        for(auto &s: vs) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

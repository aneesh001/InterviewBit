#include <bits/stdc++.h>
using namespace std;

int ladderLength(string start, string end, vector<string> &dictV) {
    dictV.push_back(start);
    dictV.push_back(end);
    int n = dictV.size();

    unordered_map<string, int> dict;
    for(int i = 0; i < n; ++i) {
        dict[dictV[i]] = i;
    }

    vector<int> vis(n, false);
    vis[dict[start]] = true;

    vector<int> dist(n, 0);
    dist[dict[start]] = 1;

    queue<int> q;
    q.push(dict[start]);

    while(!q.empty()) {
        string top = dictV[q.front()];
        q.pop();

        if(top == end) break;

        for(int i = 0; i < top.size(); ++i) {
            string tmp = top;
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                tmp[i] = ch;

                if(dict.find(tmp) != dict.end() && !vis[dict[tmp]]) {
                    vis[dict[tmp]] = true;
                    dist[dict[tmp]] = dist[dict[top]] + 1;
                    q.push(dict[tmp]);
                }
            }
        }
    }

    return dist[dict[end]];
}

int main(void) {
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string src, dst;
    cin >> src >> dst;

    cout << ladderLength(src, dst, words) << endl;
    return 0;
}

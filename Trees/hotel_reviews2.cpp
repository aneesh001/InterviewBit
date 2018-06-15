#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct node {
    int next[26];

    node() {
        for(int i = 0; i < 26; ++i) {
            next[i] = -1;
        }
    }
};

void add(const string &s, vector<node> &trie) {
    int current = 0;
    for(char ch: s) {
        if(trie[current].next[ch - 'a'] != -1) {
            current = trie[current].next[ch - 'a'];
        }
        else {
            trie.push_back(node());
            trie[current].next[ch - 'a'] = trie.size() - 1;
            current = trie.size() - 1;
        }
    }
}

void add_all(const string &s, vector<node> &trie) {
    for(int i = 0; i < s.size(); ++i) {
        string w;
        while(i < s.size() && s[i] != '_') {
            w += s[i];
            ++i;
        }
        add(w, trie);
    }
}

bool find(const string &s, vector<node> &trie) {
    int current = 0;
    for(char ch: s) {
        if(trie[current].next[ch - 'a'] != -1) {
            current = trie[current].next[ch - 'a'];
        }
        else {
            return false;
        }
    }
    return true;
}

int find_all(const string &s, vector<node> &trie) {
    int count = 0;
    for(int i = 0; i < s.size(); ++i) {
        string w;
        while(i < s.size() && s[i] != '_') {
            w += s[i];
            ++i;
        }
        if(find(w, trie)) {
            ++count;
        }
    }
    return count;
}

vector<int> solve(string a, vector<string> &b) {
    vector<node> trie;
    trie.push_back(node());
    add_all(a, trie);

    vector<pair<int, int>> reviews;
    for(int i = 0; i < b.size(); ++i) {
        reviews.push_back({find_all(b[i], trie), i});
    }

    stable_sort(reviews.begin(), reviews.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });

    vector<int> ans;
    for(auto &p: reviews) {
        ans.push_back(p.second);
    }

    return ans;
}

int main(void) {
    return 0;
}

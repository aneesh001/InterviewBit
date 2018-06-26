#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

UndirectedGraphNode *util(UndirectedGraphNode *root) {
    UndirectedGraphNode *new_root = new UndirectedGraphNode(root->label);
    mp.insert({root, new_root});

    for(UndirectedGraphNode *n: root->neighbors) {
        if(vis.find(n) == vis.end()) {
            UndirectedGraphNode *new_child = util(n);
            new_root->neighbors.push_back(new_child);
        }
        else {
            UndirectedGraphNode *child = mp[n];
            new_root->neighbors.push_back(child);
        }
    }

    return new_root;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    vis.clear();
    if(node == nullptr) return nullptr;
    else return util(node);
}

int main(void) {
    return 0;
}

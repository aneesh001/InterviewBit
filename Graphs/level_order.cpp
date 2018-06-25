#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A == nullptr) return ans;

    vector<TreeNode*> level;
    level.push_back(A);

    while(level.size() != 0) {
        vector<int> to_add;
        for(TreeNode *t: level) to_add.push_back(t->val);
        ans.push_back(to_add);
        vector<TreeNode*> new_level;

        for(TreeNode *t: level) {
            if(t->left != nullptr) new_level.push_back(t->left);
            if(t->right != nullptr) new_level.push_back(t->right);
        }

        level = new_level;
    }

    return ans;
}

int main(void) {
    return 0;
}

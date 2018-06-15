#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

void util(TreeNode *r, int key, int &sum, vector<int> &path, vector<vector<int>> &ans) {
    sum += r->val;
    path.push_back(r->val);

    if(r->left == nullptr && r->right == nullptr && sum == key) {
        ans.push_back(path);
    }
    if(r->left != nullptr) {
        util(r->left, key, sum, path, ans);
    }

    if(r->right != nullptr) {
        util(r->right, key, sum, path, ans);
    }

    sum -= r->val;
    path.pop_back();
}

int main(void) {
    return 0;
}

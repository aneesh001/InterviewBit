#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

struct comp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    }
};

TreeNode *util(vector<int> &A, int low, int high) {
    if(low <= high) {
        int max_idx = low;
        for(int i = low; i <= high; ++i) {
            if(A[i] > A[max_idx]) {
                max_idx = i;
            }
        }

        TreeNode *root = new TreeNode(A[max_idx]);
        root->left = util(A, low, max_idx - 1);
        root->right = util(A, max_idx + 1, high);

        return root;
    }
    else {
        return nullptr;
    }
}

TreeNode *buildTree(vector<int> &A) {
    return util(A, 0, A.size() - 1);
}

int main(void) {
    return 0;
}

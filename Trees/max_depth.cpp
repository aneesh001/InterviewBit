#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

int maxDepth(TreeNode* A) {
    if(A == nullptr) {
        return 0;
    }
    else return 1 + max(maxDepth(A->left), maxDepth(A->right));
}

int main(void) {
    return 0;
}

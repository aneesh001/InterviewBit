#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

TreeNode *invertTree(TreeNode *A) {
    if(A == nullptr) {
        return nullptr;
    }

    TreeNode *tmp = A->left;
    A->left = invertTree(A->right);
    A->right = invertTree(tmp);

    return A;
}

int main(void) {
    return 0;
}

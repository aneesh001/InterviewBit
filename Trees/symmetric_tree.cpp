#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};


int util(TreeNode *a, TreeNode *b) {
    if(a == nullptr && b == nullptr) {
        return 1;
    }
    else if(a == nullptr && b != nullptr) {
        return 0;
    }
    else if(a != nullptr && b == nullptr) {
        return 0;
    }
    else {
        if(a->val != b->val) return 0;
        else return util(a->left, b->right) && util(a->right, b->left);
    }
}


int isSymmetric(TreeNode* A) {
    if(A == nullptr) {
        return 1;
    }
    else {
        return util(A->left, A->right);
    }
}

int main(void) {
    return 0;
}

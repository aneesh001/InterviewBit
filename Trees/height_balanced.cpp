#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int util(TreeNode *A) {
    if(A == nullptr) {
        return 0;
    }

    int left = util(A->left);
    int right = util(A->right);

    if(left < 0 || right < 0 || abs(left - right) > 1) {
        return -1;
    }
    else {
        return 1 + max(left, right);
    }
}

int isBalanced(TreeNode* A) {
    int ans = util(A);
    if(ans >= 0) return 1;
    else return 0;
}

int main(void) {
    return 0;
}

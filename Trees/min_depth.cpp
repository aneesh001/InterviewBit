#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

int minDepth(TreeNode *A) {
    if(A == nullptr) {
        return 0;
    }
    
    int ans = INT_MAX;
    if(A->left == nullptr && A->right == nullptr) {
        return 1;
    }
    if(A->left != nullptr) {
        ans = min(ans, 1 + minDepth(A->left));
    }
    if(A->right != nullptr) {
        ans = min(ans, 1 + minDepth(A->right));
    }

    return ans;
}

int main(void) {
    return 0;
}

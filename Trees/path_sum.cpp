#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

bool util(TreeNode *r, int sum, int b) {
    sum += r->val;
    
    if(r->left == nullptr && r->right == nullptr) {
        if(sum == b) return 1;
        else return 0;
    }
    else if(r->left != nullptr && util(r->left, sum, b)) {
        return 1;
    }
    else if(r->right != nullptr && util(r->right, sum, b)) {
        return 1;
    }
    else {
        return 0;
    }
}
 
int hasPathSum(TreeNode* A, int B) {
    if(A == nullptr) return 0;
    else return util(A, 0, B);
}

int main(void) {
    return 0;
}

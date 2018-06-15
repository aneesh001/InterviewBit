#include <iostream>
#include <vector>
#define MOD 1003

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {  }
};

void util(TreeNode *A, int &sum, int &number) {
    int tmp = number;
    number = ((10 * number) + A->val) % MOD;

    if(A->left == nullptr && A->right == nullptr) {
        sum = (sum + number) % MOD;
    }
    if(A->left != nullptr) {
        util(A->left, sum, number);
    }
    if(A->right != nullptr) {
        util(A->right, sum, number);
    }

    number = tmp;
}

int sumNumbers(TreeNode *A) {
    int sum = 0;
    int number = 0;
    if(A == nullptr) {
        return sum;
    }

    util(A, sum, number);
    return sum;
}

int main(void) {
    return 0;
}

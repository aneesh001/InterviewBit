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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* sortedListToBST(ListNode* A) {
    if(A == nullptr) return nullptr;

    ListNode *prev = nullptr;
    ListNode *curr = A;
    int len = 0;
    while(curr != nullptr) {
        len++;
        curr = curr->next;
    }
    curr = A;

    for(int i = 0; i < len / 2; ++i) {
        prev = curr;
        curr = curr->next;
    }

    TreeNode *root = new TreeNode(curr->val);

    if(prev != nullptr) {
        prev->next = nullptr;
        root->left = sortedListToBST(A);
        prev->next = curr;
    }
    root->right = sortedListToBST(curr->next);

    return root;
}

int main(void) {
    return 0;
}

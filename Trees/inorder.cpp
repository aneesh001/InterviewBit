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
void util(TreeNode *A, vector<int> &ans) {
	if(A == nullptr) {
		return;
	}
	util(A->left, ans);
	ans.push_back(A->val);
	util(A->right, ans);
}

vector<int> inorderTraversal(TreeNode* A) {
	vector<int> ans;
	util(A, ans);

	return ans;
}

int main(void) {
	return 0;
}
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
vector<int> preorderTraversal(TreeNode* A) {
	vector<int> ans;
	if(A == nullptr) {
		return ans;
	}
	stack<TreeNode*> st;
	st.push(A);

	while(!st.empty()) {
		TreeNode *top = st.top();
		st.pop();
		ans.push_back(top->val);

		if(top->right != nullptr) {
			st.push(top->right);
		}

		if(top->left != nullptr) {
			st.push(top->left);
		}
	}

	return ans;
}

int main(void) {
	return 0;
}
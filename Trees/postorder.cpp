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
vector<int> postorderTraversal(TreeNode* A) {
	vector<int> ans;
	stack<TreeNode*> s1;
	stack<int> s2;
	s1.push(A);

	while(!s1.empty()) {
		TreeNode *top = s1.top();
		s1.pop();

		s2.push(top->val);

		if(top->left != nullptr) {
			s1.push(top->left);
		}

		if(top->right != nullptr) {
			s1.push(top->right);
		}
	}

	while(!s2.empty()) {
		ans.push_back(s2.top());
		s2.pop();
	}

	return ans;
}

int main(void) {
	return 0;
}
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
vector<vector<int>> verticalOrderTraversal(TreeNode* A) {
	if(A == nullptr) {
		return vector<vector<int>>();
	}
	map<int, vector<int> verts;
	queue<pair<TreeNode*, int>> q;
	q.push({A, 0});

	while(!q.empty()) {
		TreeNode * top_node = q.front().first;
		int top_vert = q.front().second;
		verts[top_vert].push_back(top_node->val);

		if(top_node->left != nullptr) {
			q.push({top_node->left, top_vert - 1});
		}
		if(top_node->right != nullptr) {
			q.push({top_node->right, top_vert + 1});
		}
	}

	vector<vector<int>> ans;
	for(auto &p: verts) {
		ans.push_back(p.second);
	}

	return ans;
}

int main(void) {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

TreeNode *util(vector<int> &pre, vector<int> &in, int i, int j, int k, int l) {
	assert(j - i == l - k);

	if(j - i < 0) {
		return nullptr;
	}
	else if(j - i == 1) {
		return new TreeNode(pre[i]);
	}
	else {
		TreeNode *root = new TreeNode(pre[i]);
		int idx = k;
		while(in[idx] != pre[i]) {
			++idx;
		}
		int len = idx - k;
		root->left = util(pre, in, i + 1, i + len, k, idx - 1);
		root->right = util(pre, in, i + len + 1, j, idx + 1, l);
		return root;
	}
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
	return util(A, B, 0, A.size() - 1, 0, B.size() - 1);
}

int main(void) {
	return 0;
}
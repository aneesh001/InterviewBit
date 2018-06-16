#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

TreeNode *util(vector<int> &in, vector<int> &post, int i, int j, int k, int l) {
	assert(j - i + 1 == l - k + 1);

	if(j - i < 0) {
		return nullptr;
	}
	else if(j - i == 0) {
		return new TreeNode(post[l]);
	}
	else {
		TreeNode *root = new TreeNode(post[l]);
		int idx = i;
		while(in[idx] != post[l]) {
			++idx;
		}
		int len = idx - i;
		root->left = util(in, post, i, idx - 1, k, k + len - 1);
		root->right = util(in, post, idx + 1, j, k + len, l - 1);
		return root;
	}
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
	return util(A, B, 0, A.size() - 1, 0, B.size() - 1);
}

int main(void) {
	return 0;
}
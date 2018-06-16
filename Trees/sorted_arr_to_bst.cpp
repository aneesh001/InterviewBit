#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

TreeNode *util(const vector<int> &A, int low, int high) {
	if(low <= high) {
		int mid = low + (high - low) / 2;
		TreeNode *root = new TreeNode(A[mid]);
		root->left = util(A, low, mid - 1);
		root->right = util(A, mid + 1, high);
		return root;
	}
	else {
		return nullptr;
	}
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    return util(A, 0, A.size() - 1);
}

int main(void) {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

pair<bool, int> util(TreeNode *A, int k) {
	if(A == nullptr) {
		return {false, 0};
	}

	pair<bool, int> l = util(A->left, k);
	if(l.first == true) {
		return l;
	}

	if(l.second + 1 == k) {
		return {true, A->val};
	}

	pair<bool, int> r = util(A->right, k - l.second - 1);
	if(r.first == true) {
		return r;
	}

	return {false, 1 + l.second + r.second};
}

int kthsmallest(TreeNode* A, int B) {
	pair<bool, int> ans = util(A, B);
	assert(ans.first == true);
	return ans.second;
}

int main(void) {
	return 0;
}
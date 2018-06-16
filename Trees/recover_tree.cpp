#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

vector<int> recoverTree(TreeNode* A) {
	vector<int> elems;
	stack<TreeNode*> st;
	TreeNode *cur = A;

	while(cur != nullptr || !st.empty()) {
		if(cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}
		else {
			cur = st.top(); st.pop();
			elems.push_back(cur->val);
			cur = cur->right;
		}
	}

	int f = 0;
	for(int i = 0; i < elems.size() - 1; ++i) {
		if(elems[i] > elems[i + 1]) {
			f = i;
			break;
		}
	}

	int s = 0;
	for(int i = elems.size() - 1; i >= 1; --i) {
		if(elems[i - 1] > elems[i]) {
			s = i;
			break;
		}
	}

	return vector<int> {min(elems[f], elems[s]), max(elems[f], elems[s])};
}

int main(void) {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *A, vector<int> &euler, vector<int> &height, int h) {
	if(A == nullptr) {
		return;
	}

	euler.push_back(A->val);
	height.push_back(h);

	dfs(A->left, euler, height, h + 1);
	dfs(A->right, euler, height, h + 1);

	euler.push_back(A->val);
	height.push_back(h);
}

int lca(TreeNode *A, int B, int C) {
	vector<int> euler;
	vector<int> height;
	dfs(A, euler, height, 0);

	int first_b = -1;
	for(int i = 0; i < euler.size(); ++i) {
		if(euler[i] == B) {
			first_b = i;
			break;
		}
	}

	int first_c = -1;
	for(int i = 0; i < euler.size(); ++i) {
		if(euler[i] == C) {
			first_c = i;
			break;
		}
	}

	if(first_c == -1 || first_b == -1) {
		return -1;
	}

	int i = min(first_c, first_b);
	int j = min(first_b, first_c);
	int ans_ht = height[i];
	int ans_val = euler[i];
	while(i <= j) {
		if(height[i] < ans_ht) {
			ans_ht = height[i];
			ans_val = euler[i];
		}
		++i;
	}

	return ans_val;
}

int main(void) {
	return 0;
}
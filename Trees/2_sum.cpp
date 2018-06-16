#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) { }
};

int t2Sum(TreeNode* A, int B) {
	stack<TreeNode*> s1, s2;
	TreeNode *in = A;
	TreeNode *rev = A:
	int move1 = 1;
	int move2 = 1;
	int val1 = 0, val2 = 0;

	while(true) {
		while(move1) {
			if(in != nullptr) {
				s1.push(in);
				in = in->left;
			}
			else {
				if(s1.empty()) {
					move1 = 0;
				}
				else {
					in = s1.top();
					s1.pop();
					val1 = in->val;
					in = in->right;
					move1 = 0;
				}
			}
		}

		while(move2) {
			if(rev != nullptr) {
				s2.push(rev);
				rev = rev->right;
			}
			else {
				if(s2.empty()) {
					move2 = 0;
				}
				else {
					rev = s2.top(); s2.pop();
					val2 = rev->val;
					rev = rev->left;
					move2 = 0;
				}
			}
		}

		if(val1 != val2 && val1 + val2 == B) {
			return 1;
		}
		else if(val1 + val2 > B) {
			move2 = 1;
		}
		else if(val1 + val2 < B) {
			move1 = 1;
		}

		if(val1 >= val2) {
			return 0;
		}
	}
}

int main(void) {
	return 0;
}
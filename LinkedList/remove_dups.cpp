#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A) {
	if(A == nullptr) {
		return A;
	}

	ListNode *i = A;
	ListNode *j = A->next;

	while(j != nullptr) {
		if(i->val != j->val) {
			i->next = j;
			i = i->next;
		}
		else if(i->val == j->val && j->next == nullptr) {
			i->next = nullptr;
		}

		j = j->next;
	}

	return A;
}

int main(void) {

}
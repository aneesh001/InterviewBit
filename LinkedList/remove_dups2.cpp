#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A) {
	if(A == nullptr || A->next == nullptr) {
		return A;
	}

	ListNode *head = nullptr;
	ListNode *lastUnique = nullptr;
	ListNode *i = A;

	while(i != nullptr) {
		if(i->next == nullptr) {
			if(lastUnique == nullptr) {
				head = lastUnique = i;
				i = i->next;
				lastUnique->next = nullptr;
			}
			else {
				lastUnique->next = i;
				lastUnique = i;
				i = i->next;
				lastUnique->next = nullptr;
			}
		}
		else {
			ListNode *j = i->next;

			if(i->val == j->val) {
				while(j != nullptr && j->val == i->val) {
					j = j->next;
				}

				i = j;
			}
			else {
				if(lastUnique == nullptr) {
					head = lastUnique = i;
					i = i->next;
					lastUnique->next = nullptr;
				}
				else {
					lastUnique->next = i;
					lastUnique = i;
					i = i->next;
					lastUnique->next = nullptr;
				}
			}
		}
	}

	return head;
}

int main(void) {

}
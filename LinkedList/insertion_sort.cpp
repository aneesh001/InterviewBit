#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* A) {
	ListNode *sorted = nullptr;

	ListNode *curr = A;
	ListNode *next;

	while(curr != nullptr) {
		next = curr->next;

		if(sorted == nullptr) {
			sorted = curr;
			curr->next = nullptr;
		}
		else {
			ListNode *prev = nullptr;
			ListNode *i = sorted;

			while(i != nullptr && i->val < curr->val) {
				prev = i;
				i = i->next;
			}

			if(prev != nullptr) {
				curr->next = i;
				prev->next = curr;
			}
			else {
				curr->next = sorted;
				sorted = curr;
			}
		}

		curr = next;
	}

	return sorted;
}

int main(void) {

}
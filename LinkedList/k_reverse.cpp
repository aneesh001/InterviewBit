#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* A, int B) {
	ListNode *head = nullptr;
	ListNode *p_tail = nullptr;

	ListNode *curr = A;

	while(cur != nullptr) {
		ListNode *prev = nullptr;
		ListNode *next;
		ListNode *c_tail = cur;
		int count = 0;
		while(count < B) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;

			++count;
		}

		if(p_tail == nullptr) {
			head = p_tail = prev;
			p_tail = c_tail;
		}
		else {
			p_tail->next = prev;
			p_tail = c_tail;
		}
	}

	return head;
}

int main(void) {

}
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
	ListNode *head = nullptr;
	ListNode *tail = nullptr;

	ListNode *i = A;
	ListNode *j = B;
	int carry = 0;

	while(i != nullptr || j != nullptr) {
		int s = carry;

		if(i != nullptr) {
			s += i->val;
			i = i->next;
		}

		if(j != nullptr) {
			s += j->val;
			j = j->next;
		}

		ListNode *nn = new ListNode(s % 10);

		if(head == nullptr) {
			head = tail = nn;
		}
		else {
			tail->next = nn;
			tail = nn;
		}

		carry = s / 10;
	}

	while(carry) {
		ListNode *nn = new ListNode(carry % 10);

		if(head == nullptr) {
			head = tail = nn;
		}
		else {
			tail->next = nn;
			tail = nn;
		}

		carry /= 10;
	}

	ListNode *last_non_zero = nullptr;
	ListNode *cur = head;

	while(cur != nullptr) {
		if(cur->val != 0) {
			last_non_zero = cur;
		}

		cur = cur->next;
	}

	last_non_zero->next = nullptr;

	return head;
}

int main(void) {

}
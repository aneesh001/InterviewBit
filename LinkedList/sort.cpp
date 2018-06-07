#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
	if(A == nullptr && B == nullptr) {
		return nullptr;
	}
	else if(A == nullptr) {
		return B;
	}
	else if(B == nullptr) {
		return A;
	}

	ListNode *i = A;
	ListNode *j = B;
	
	ListNode *head;
	ListNode *prev;
	if(i->val <= j->val) {
		prev = head = i;
		i = i->next;
	}
	else {
		prev = head = j;
		j = j->next;
	}
	prev->next = nullptr;

	while(i != nullptr || j != nullptr) {
		if(i == nullptr) {
			prev->next = j;
			j = nullptr;
		}
		else if(j == nullptr) {
			prev->next = i;
			i = nullptr;
		}
		else if(i->val <= j->val) {
			prev->next = i;
			prev = i;
			i = i->next;
		}
		else {
			prev->next = j;
			prev = j;
			j = j->next;
		}
	}

	return head;
}

ListNode* sortList(ListNode* A) {
	int size = 0;
	ListNode *curr = A;
	while(curr != nullptr) {
		++size;
		curr = curr->next;
	}

	if(size > 1) {
		ListNode *prev = nullptr;
		curr = A;

		for(int i = 0; i < size / 2; ++i) {
			prev = curr;
			curr = curr->next;
		}

		prev->next = nullptr;

		A = sortList(A);
		curr = sortList(curr);

		return mergeTwoLists(A, curr);
	}
	else {
		return A;
	}
}

int main(void) {

}
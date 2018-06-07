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

int main(void) {

}
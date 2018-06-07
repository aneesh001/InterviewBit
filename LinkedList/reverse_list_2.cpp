#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* A, int B, int C) {
	if(B == C) {
		return A;
	}

	B--; C--;

	ListNode *prev = nullptr;
	ListNode *cur = A;
	int ci = 0;

	while(ci != B) {
		prev = cur;
		cur = cur->next;
		++ci;
	}

	ListNode *just_b4 = prev;
	ListNode *tail_rev = cur;
	ListNode *next;
	prev = nullptr;

	while(ci <= C) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		++ci;
	}

	if(just_b4 == nullptr) {
		A = prev;
	}
	else {
		just_b4->next = prev;
	}

	if(cur != nullptr) {
		tail_rev = cur;
	}

	return A;
}

int main(void) {

}
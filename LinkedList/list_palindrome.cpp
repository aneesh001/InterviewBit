#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
int lPalin(ListNode* A) {
	int size = 0;
	ListNode *crawler = A;
	while(crawler != nullptr) {
		++size;
		crawler = crawler->next;
	}

	if(size == 0 || size == 1) {
		return 1;
	}

	Node *other = A;
	int to_adv = (size % 2 == 0) ? (size / 2) : (size / 2 + 1);

	for(int i = 0; i < to_adv; ++i) {
		other = other->next;
	}

	ListNode *prev = nullptr;
	ListNode *cur = other;
	ListNode *next;

	while(cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	for(int i = 0; i < size / 2; ++i) {
		if(A->val != prev->val) {
			return 0;
		}

		A = A->next;
		prev = prev->next;
	}

	return 1;
}

int main(void) {
	
}

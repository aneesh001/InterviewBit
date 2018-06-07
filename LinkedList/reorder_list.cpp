#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reorderList(ListNode* A) {
	int size = 0;
	ListNode *crawler = A;
	while(crawler != nullptr) {
		++size;
		crawler = crawler->next;
	}

	if(size <= 2) {
		return A;
	}

	int to_adv = (size % 2 == 0) ? (size / 2) : (size / 2 + 1);

	ListNode *prev = nullptr;
	ListNode *cur = A;
	ListNode *next;

	for(int i = 0; i < to_adv; ++i) {
		prev = cur;
		cur = cur->next;
	}

	prev->next = nullptr;

	ListNode *i = A;

	prev = nullptr;

	while(cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	ListNode *j = prev;
	ListNode *ni;
	ListNode *nj;

	while(j != nullptr) {
		ni = i->next;
		nj = j->next;
		i->next = j;
		j->next = i->next;

		i = ni;
		j = nj;
	}

	return A;
}

int main(void) {

}
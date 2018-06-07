#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* A, int B) {
	int size = 0;
	ListNode *crawler = A;
	while(crawler != nullptr) {
		++size;
		crawler = crawler->next;
	}

	if(size == 0 || B % size == 0) {
		return A;
	}

	B = B % size;

	int to_adv = size - B;

	ListNode *prev = nullptr;
	ListNode *cur = A;

	while(n != 0) {
		prev = cur;
		cur = cur->next;
		n--;
	}

	assert(prev != nullptr);

	while(cur->next != nullptr) {
		cur = cur->next;
	}

	cur->next = head;
	head = prev->next;
	prev->next = nullptr;

	return head;
}

int main(void) {

}
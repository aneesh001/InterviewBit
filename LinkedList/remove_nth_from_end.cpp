#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* A, int B) {
	int size = 0;
	ListNode *crawler = A;
	while(crawler != nullptr) {
		size++;
		crawler = crawler->next;
	}

	if(size == 0) {
		return A;
	}

	if(B > size) {
		return A->next;
	}

	int n = size - B;
	ListNode *prev = nullptr;
	ListNode *cur = A;

	while(n != 0) {
		prev = cur;
		cur = cur->next;
		n--;
	}

	if(prev == nullptr) {
		return cur->next;
	}
	else {
		prev->next = cur->next;
		return A;
	}
}

int main(void) {

}
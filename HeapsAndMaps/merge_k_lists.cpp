#include <bits/stdc++.h>
using namespace std;

struct ListNode {
   	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
	bool operator()(ListNode *a, ListNode *b) {
		return a->val < b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*> &A) {
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	priority_queue<ListNode*, vector<ListNode*>, compare()> pq;
	for(int i = 0; i < A.size(); ++i) {
		if(A[i] != nullptr) pq.push(A[i]);
	}
	while(!pq.empty()) {
		ListNode *top = pq.top();
		pq.pop();

		if(top->next != nullptr) pq.push(top->next);

		if(head == nullptr) {
			head = tail = top;
		}
		else {
			tail->next = top;
			tail = tail->next;
		}
	}

	tail->next = nullptr;

	return head;
}

int main(void) {
	return 0;
}
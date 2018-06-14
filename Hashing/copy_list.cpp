#include <bits/stdc++.h>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* A) {
	if(A == nullptr) return A;
	
	RandomListNode *head = nullptr, *tail = nullptr, *current = A, *other = nullptr;
	unordered_map<RandomListNode*, RandomListNode*> mp;
	decltype(mp.begin()) it;
	
	while(current != nullptr) {
		RandomListNode *nn = new RandomListNode(current->label);
		
		if(head == nullptr) {
			head = tail = nn;
		}
		else {
			tail->next = nn;
			tail = nn;
		}
		
		if(current->random != nullptr) {
			mp.insert({current->random, nn});
		}
		
		current = current->next;
	}
	
	current = A;
	other = head;
	
	while(current != nullptr) {
		it = mp.find(current);
		
		if(it != mp.end()) {
			it->second->random = other;
		}
		
		current = current->next;
		other = other->next;
	}
	
	return head;
}

int main(void) {
	return 0;
}
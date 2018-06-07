#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* A) {
    if(A == nullptr || A->next == nullptr) {
    	return nullptr;
    }

    ListNode *slow = A;
    ListNode *fast = A->next;

    while(slow != fast) {
    	if(slow->next == nullptr) {
    		return nullptr;
    	}
    	else {
    		slow = slow->next;
    	}

    	if(fast->next == nullptr || fast->next->next == nullptr) {
    		return nullptr;
    	}
    	else {
    		fast = fast->next->next;
    	}
    }

    int size = 1;
    slow = fast->next;

    while(slow != fast) {
    	++size;
    	slow = slow->next;
    }

    slow = A;
    fast = A;

    while(size > 0) {
    	fast = fast->next;
    	size--;
    }

    while(slow != fast) {
    	slow = slow->next;
    	fast = fast->next;
    }

    return slow;
}

int main(void) {

}
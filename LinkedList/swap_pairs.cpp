#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* A) {
	if(A == nullptr || A->next == nullptr) {
        return A;
    }
    
    ListNode *cur = A;
    ListNode *next, *nn;
    ListNode *prev = nullptr;
    ListNode *head = nullptr;

    while(cur != nullptr && cur->next != nullptr) {
        next = cur->next;
        nn = next->next;

        next->next = cur;
        cur->next = nn;

        if(head == nullptr) {
            head = next;
        }
        
        if(prev != nullptr) {
            prev->next = next;
        }
        prev = cur;

        cur = nn;
    }

    return head;
}

int main(void) {

}
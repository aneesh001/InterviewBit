#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* A, int B) {
	ListNode *ins = nullptr;
    ListNode *prev = nullptr;
    ListNode *curr = A;

    while(curr != nullptr) {
        if(curr->val < B && ins == nullptr) {
            if(prev == nullptr) {
                prev = curr;
                ins = curr;
                curr = curr->next;
            }
            else {
                prev->next = curr->next;
                curr->next = A;
                A = curr;
                curr = prev->next;
                ins = A;
            }
        }
        else if(curr->val < B && ins->next == curr) {
            prev = curr;
            ins = curr;
            curr = curr->next;
        }
        else if(curr->val < B) {
            prev->next = curr->next;
            curr->next = ins->next;
            ins->next = curr;
            ins = ins->next;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return A;
}

int main(void) {

}
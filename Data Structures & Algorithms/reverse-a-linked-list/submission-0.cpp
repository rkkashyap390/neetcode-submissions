/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* w = NULL;
        ListNode* x = head;
        ListNode* y = head->next;
        while(y!=NULL){
            x->next = w;
            w = x;
            x = y;
            y = y->next;
        }
        x->next = w;
        return x;
    }
};

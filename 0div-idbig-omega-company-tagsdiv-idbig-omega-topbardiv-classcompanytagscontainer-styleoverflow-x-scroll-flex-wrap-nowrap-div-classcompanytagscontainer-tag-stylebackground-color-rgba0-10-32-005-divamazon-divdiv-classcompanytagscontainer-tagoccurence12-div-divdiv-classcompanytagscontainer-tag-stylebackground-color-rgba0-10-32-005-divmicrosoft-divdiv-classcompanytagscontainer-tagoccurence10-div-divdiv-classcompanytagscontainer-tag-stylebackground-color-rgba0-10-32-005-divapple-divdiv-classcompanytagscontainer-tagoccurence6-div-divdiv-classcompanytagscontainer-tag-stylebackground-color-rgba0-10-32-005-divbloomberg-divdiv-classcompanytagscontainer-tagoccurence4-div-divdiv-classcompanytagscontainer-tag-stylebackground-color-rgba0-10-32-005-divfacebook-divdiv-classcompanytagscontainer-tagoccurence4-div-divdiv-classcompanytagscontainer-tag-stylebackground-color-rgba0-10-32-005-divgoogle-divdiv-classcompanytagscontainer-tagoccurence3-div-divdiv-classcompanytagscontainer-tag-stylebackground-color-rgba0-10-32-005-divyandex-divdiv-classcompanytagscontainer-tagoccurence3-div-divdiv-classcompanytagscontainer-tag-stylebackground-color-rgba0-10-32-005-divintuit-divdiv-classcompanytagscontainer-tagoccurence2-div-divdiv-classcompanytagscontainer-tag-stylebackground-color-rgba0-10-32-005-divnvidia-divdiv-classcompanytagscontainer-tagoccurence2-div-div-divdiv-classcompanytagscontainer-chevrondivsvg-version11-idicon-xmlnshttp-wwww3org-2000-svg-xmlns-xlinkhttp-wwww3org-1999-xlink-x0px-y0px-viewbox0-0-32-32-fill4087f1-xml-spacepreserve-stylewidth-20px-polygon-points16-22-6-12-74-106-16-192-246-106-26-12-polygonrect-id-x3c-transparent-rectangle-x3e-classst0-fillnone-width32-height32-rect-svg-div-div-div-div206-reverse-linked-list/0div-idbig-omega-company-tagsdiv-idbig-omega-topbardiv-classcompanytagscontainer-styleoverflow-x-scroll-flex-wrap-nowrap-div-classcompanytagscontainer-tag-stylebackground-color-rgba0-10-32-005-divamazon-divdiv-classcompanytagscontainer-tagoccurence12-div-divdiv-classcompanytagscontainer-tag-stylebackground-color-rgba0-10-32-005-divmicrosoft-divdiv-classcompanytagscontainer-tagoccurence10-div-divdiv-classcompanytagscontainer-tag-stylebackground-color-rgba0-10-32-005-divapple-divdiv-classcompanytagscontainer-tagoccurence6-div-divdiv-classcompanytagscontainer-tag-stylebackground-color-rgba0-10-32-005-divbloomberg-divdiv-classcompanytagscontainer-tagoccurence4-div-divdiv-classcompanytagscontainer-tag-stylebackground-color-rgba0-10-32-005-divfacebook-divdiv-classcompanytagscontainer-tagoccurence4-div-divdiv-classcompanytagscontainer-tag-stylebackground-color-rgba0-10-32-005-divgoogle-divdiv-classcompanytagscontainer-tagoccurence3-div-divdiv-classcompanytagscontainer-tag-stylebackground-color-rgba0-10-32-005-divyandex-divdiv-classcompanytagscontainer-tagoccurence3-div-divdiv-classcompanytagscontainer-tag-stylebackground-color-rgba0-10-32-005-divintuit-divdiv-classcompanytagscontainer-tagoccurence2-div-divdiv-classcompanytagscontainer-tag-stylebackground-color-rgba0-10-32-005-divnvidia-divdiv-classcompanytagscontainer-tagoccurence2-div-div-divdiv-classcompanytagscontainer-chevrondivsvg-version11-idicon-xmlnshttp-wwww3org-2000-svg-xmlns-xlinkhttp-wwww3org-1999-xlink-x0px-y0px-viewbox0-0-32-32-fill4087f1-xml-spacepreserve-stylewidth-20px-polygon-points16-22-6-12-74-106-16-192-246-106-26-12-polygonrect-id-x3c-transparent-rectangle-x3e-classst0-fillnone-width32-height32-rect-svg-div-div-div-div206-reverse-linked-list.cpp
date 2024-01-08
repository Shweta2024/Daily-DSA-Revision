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
    
    ListNode* reverseLL(ListNode*current, ListNode* prev, ListNode* nxt)
    {
        if(!current)
            return prev;
        current->next = prev;
        prev = current;
        current = nxt;

        if(nxt)
            nxt =nxt->next;
        return reverseLL(current,prev,nxt);
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        return reverseLL(head,NULL,head->next);
    }
};
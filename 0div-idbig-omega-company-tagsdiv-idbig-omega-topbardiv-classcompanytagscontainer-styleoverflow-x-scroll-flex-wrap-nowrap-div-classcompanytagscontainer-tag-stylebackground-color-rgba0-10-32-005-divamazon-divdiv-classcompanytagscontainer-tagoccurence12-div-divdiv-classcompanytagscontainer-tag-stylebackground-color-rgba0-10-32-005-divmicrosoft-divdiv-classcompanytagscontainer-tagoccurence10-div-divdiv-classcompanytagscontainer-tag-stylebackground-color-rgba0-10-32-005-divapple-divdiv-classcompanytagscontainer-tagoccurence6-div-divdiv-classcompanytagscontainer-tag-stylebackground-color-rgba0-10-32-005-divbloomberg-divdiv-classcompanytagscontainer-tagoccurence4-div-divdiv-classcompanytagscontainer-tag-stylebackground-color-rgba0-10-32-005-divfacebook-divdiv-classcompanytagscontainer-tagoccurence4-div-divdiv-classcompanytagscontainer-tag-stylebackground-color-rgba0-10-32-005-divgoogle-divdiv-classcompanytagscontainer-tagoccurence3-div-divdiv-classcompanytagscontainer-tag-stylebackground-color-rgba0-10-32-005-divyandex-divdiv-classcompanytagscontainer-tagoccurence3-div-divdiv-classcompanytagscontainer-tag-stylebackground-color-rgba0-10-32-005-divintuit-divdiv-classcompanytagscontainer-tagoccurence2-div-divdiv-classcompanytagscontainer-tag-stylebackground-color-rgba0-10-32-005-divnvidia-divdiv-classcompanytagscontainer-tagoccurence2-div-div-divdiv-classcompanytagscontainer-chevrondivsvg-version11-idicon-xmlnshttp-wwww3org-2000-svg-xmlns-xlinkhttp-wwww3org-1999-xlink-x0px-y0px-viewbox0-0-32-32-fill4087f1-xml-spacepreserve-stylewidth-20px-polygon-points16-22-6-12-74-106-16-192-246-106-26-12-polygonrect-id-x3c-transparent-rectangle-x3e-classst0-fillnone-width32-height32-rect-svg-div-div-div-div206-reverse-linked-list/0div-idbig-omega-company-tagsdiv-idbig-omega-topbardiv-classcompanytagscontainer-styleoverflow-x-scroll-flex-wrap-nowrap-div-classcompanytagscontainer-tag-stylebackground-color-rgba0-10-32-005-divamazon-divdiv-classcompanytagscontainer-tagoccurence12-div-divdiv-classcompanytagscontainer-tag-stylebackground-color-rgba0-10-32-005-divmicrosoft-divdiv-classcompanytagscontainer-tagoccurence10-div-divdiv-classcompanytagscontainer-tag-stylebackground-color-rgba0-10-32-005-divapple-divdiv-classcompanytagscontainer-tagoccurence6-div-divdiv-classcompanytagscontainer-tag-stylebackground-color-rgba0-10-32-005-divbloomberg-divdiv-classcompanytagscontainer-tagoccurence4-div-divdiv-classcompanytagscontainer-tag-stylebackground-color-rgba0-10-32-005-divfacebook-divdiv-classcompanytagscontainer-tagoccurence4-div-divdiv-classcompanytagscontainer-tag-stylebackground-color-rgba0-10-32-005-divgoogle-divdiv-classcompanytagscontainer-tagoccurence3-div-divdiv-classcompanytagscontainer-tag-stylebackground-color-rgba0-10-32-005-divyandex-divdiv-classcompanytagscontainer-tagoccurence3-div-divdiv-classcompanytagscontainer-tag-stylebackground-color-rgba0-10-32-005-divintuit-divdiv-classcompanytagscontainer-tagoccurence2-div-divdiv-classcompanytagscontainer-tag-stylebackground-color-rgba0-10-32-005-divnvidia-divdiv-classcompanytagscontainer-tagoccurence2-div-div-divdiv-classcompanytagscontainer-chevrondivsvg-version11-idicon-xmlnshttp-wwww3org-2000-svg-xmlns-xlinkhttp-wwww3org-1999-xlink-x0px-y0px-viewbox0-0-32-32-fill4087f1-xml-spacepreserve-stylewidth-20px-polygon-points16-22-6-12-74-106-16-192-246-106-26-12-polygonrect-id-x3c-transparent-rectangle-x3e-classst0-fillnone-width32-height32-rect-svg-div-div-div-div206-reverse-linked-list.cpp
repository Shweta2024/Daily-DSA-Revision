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
    
    ListNode* reverseLL(ListNode* head)
    {
        if(!head || !head->next) return head;

        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;

        while(current)
        {
            current->next = prev;
            prev = current;
            current = nxt;

            if(nxt) 
                nxt = nxt->next;
        } 
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseLL(head);
    }
};
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
    
    int findLength(ListNode* head)
    {
        int n =0;
        ListNode* current = head;
        while(current)
        {
            n++;
            current = current->next;
        }
        return n;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;
        tail->next = head;
        
        int len = findLength(head);
        
        len = len-n;
    
        while(len--)
            tail = tail->next;
        
        tail->next = tail->next->next;
        return newHead->next;
    }
};
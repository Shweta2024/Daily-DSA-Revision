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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* lessHead = new ListNode(-1);
        ListNode* lessTail = lessHead;
        
        ListNode* greaterEqHead = new ListNode(-1);
        ListNode* greaterEqTail = greaterEqHead;
        
        ListNode* current = head;
        
        while(current)
        {
            if(current->val < x)
            {
                lessTail->next = current;
                lessTail = lessTail->next;
            }
            else
            {
                greaterEqTail->next = current;
                greaterEqTail = greaterEqTail->next;
            }
            current = current->next;
        }
        lessTail->next = greaterEqHead->next;
        greaterEqTail->next = NULL;
        
        return lessHead->next;
    }
};
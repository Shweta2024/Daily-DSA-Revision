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
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head; // [] or [1]
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nxt = head->next;
        
        while(current)
        {
            current->next = prev;
            prev = current;
            current = nxt;
            if(nxt) nxt = nxt->next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        if(head->next == NULL || head->next->next == NULL) return; // [1] or [1,2]
        
        // Step1 : find mid of LL
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        
        //Step2 : reverse LL from slow(middle) to end
        ListNode* reverseHead = reverse(slow);
        // Step3 : reorder
        ListNode* current = head;
        ListNode* nxt = head->next;
        ListNode* reverseHeadNext = NULL;
        if(reverseHead) reverseHeadNext = reverseHead->next;
        
        while(current && reverseHead)
        {
            current->next = reverseHead;
            
            if(!nxt) return ;
            
            reverseHead->next = nxt;
            
            if(current->next) current = current->next->next;
            if(current) nxt = current->next;
            reverseHead = reverseHeadNext;
            if(reverseHead) reverseHeadNext = reverseHead->next;
        }
        
    }
};
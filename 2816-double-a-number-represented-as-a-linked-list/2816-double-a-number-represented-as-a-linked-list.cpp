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
    
    ListNode* findDoube(ListNode* head)
    {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* current = newHead->next;
        ListNode* prev = NULL;
        
        int carry = 0;
        
        while(current)
        {
            int res = current->val + current->val + carry;
            int sum = res%10;
            carry = res/10;
            
            prev = current;
            current->val = sum;
            current = current->next;
        }
        if(carry)
            prev->next = new ListNode(carry);
            
        return newHead->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;// [] or [1]
        
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
    
    //981
    ListNode* doubleIt(ListNode* head) 
    {
        ListNode* newHead = new ListNode(-1);
        newHead->next = reverse(head);
        
        //find double
        newHead->next = findDoube(newHead->next);
        
        //reverse again
        newHead->next = reverse(newHead->next);
        
        return newHead->next;
    }
};
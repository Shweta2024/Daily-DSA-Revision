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
        if(!head || !head->next) return head;
        
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
        if(!head || !head->next || !head->next->next) return ;
        
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
        // cout<<"slow: "<<slow->val<<endl;
        
        ListNode* reverseHead = reverse(slow);
        ListNode* reverseHeadNxt = NULL;
        if(reverseHead) reverseHeadNxt = reverseHead->next;
        // cout<<"::::"<<reverseHead->val<<endl;
        ListNode* current = head;
        ListNode* nxt = head->next;
        // while(current)
        // {
        //     cout<<current->val<<endl;
        //     current = current->next;
        // }
        while(current && reverseHead)
        {
            // cout<<current->val<<":"<<reverseHead->val<<endl;
            current->next = reverseHead;
            if(!nxt) return;
            
            reverseHead->next = nxt;
            
            if(current->next) current = current->next->next;
            if(current) nxt = current->next;
            reverseHead = reverseHeadNxt;
            if(reverseHead) reverseHeadNxt = reverseHead->next;
        }
    }
};
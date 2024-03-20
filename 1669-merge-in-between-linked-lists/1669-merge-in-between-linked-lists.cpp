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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* current = list1;
        ListNode* from = NULL;
        ListNode* to = NULL;
        a -= 1;
        int i = 0;
        int j = 0;
        while(i < a || j < b)
        {
            if(i == a)
                from = current;
            current = current->next;
            i++;
            j++;
        }
        to = current;
        from->next = list2;
        
        current = list2;
        while(current->next != NULL)
            current = current->next;
        
        current->next = to->next;
        return list1;
    }
};
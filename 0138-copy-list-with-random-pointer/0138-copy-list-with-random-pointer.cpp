/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}; 
*/

class Solution {
public:
    
    void mergeLists(Node* head)
    {
        Node* current = head;
        
        while(current)
        {
            Node* nxt = current->next;
            current->next = new Node(current->val);
            current->next->next = nxt;
            
            current = current->next->next;
        }
    }
    
    void populateRandom(Node* head)
    {
        Node* current = head;
        
        while(current)
        {
            if(current->random)
                current->next->random = current->random->next;
            current = current->next->next;
        }
    }
    
    
    Node* detachLists(Node* head)
    {
        Node* newHead = new Node(-1);
        Node* tail = newHead;
        Node* current = head;
        
        while(current)
        {
            Node* copy = current->next;
            current->next = current->next->next;
            tail->next = copy;
            
            tail = tail->next;
            current = current->next;
        }
        return newHead->next;
    }
    
    Node* copyRandomList(Node* head) 
    {
        mergeLists(head);
        
        populateRandom(head);
        
        Node* newHead = detachLists(head);
        
        return newHead;
    }
};
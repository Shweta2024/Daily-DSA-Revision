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
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*,Node*>memo;
        Node* current = head;
        while(current)
        {
            Node* copy = new Node(current->val);
            memo[current] = copy;
            current = current->next;
        }
        
        //populate random & next pointers
        for(auto current : memo)
        {
            if(current.first->next)
                memo[current.first]->next = memo[current.first->next];
            
            if(current.first->random)
                memo[current.first]->random = memo[current.first->random];
        }
        return memo[head];
    }
};
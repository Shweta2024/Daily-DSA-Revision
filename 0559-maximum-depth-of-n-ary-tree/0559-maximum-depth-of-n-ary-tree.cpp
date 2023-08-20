/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int findMaxDepth(Node* root)
    {
        if(root == NULL) return 0;
        
        int ans = 1;
        for(auto adjacent : root->children)
        {
            int temp = 1 + findMaxDepth(adjacent);
            ans = max(ans,temp);
        }
        
        return ans;
    }
    
    int maxDepth(Node* root) 
    {
        return findMaxDepth(root);
    }
};
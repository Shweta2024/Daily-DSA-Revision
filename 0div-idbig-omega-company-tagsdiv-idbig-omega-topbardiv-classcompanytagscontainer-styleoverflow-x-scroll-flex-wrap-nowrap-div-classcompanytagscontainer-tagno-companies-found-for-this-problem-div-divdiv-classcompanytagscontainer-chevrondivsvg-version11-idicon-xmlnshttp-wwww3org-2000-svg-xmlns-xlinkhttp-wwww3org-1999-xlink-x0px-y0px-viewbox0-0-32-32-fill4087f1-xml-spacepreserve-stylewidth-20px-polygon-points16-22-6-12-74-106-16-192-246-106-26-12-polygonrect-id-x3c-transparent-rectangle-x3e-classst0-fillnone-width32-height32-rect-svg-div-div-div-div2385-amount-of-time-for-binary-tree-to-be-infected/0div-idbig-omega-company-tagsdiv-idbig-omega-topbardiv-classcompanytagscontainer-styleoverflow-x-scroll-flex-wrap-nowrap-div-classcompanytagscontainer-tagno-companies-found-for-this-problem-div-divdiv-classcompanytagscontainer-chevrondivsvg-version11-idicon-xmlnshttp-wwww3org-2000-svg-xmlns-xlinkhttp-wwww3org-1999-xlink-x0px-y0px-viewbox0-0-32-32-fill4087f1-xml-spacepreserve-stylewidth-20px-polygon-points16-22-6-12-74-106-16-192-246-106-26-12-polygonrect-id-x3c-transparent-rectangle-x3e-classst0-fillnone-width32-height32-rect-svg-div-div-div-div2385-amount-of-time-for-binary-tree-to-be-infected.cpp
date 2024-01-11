/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int timeRequired(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent, unordered_map<TreeNode*,bool>&vist)
    {
        // if root is null or already visited return a 0
        if(!root || vist[root]) return 0;
        
        vist[root] = true; // mark the current node as visited
        
        // explore the possibilities
        int up = 1 + timeRequired(parent[root],parent,vist);
        int leftAns = 1 + timeRequired(root->left,parent,vist);
        int rightAns = 1 + timeRequired(root->right,parent,vist);
        
        return max(up,max(leftAns,rightAns));
    }
    
    void populateParent(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*,TreeNode*>&parent)
    {
        if(!root) return;
        
        parent[root] = prev;
        
        // make left & right call to populate parents of rest nodes
        populateParent(root->left,root,parent);
        populateParent(root->right,root,parent);
    }
    
    TreeNode* findStartNode(TreeNode* root, int start)
    {
        if(!root) return NULL;
        
        if(root-> val == start) return root;
        
        TreeNode* leftAns = findStartNode(root->left,start);
        TreeNode* rightAns = findStartNode(root->right,start);
        
        if(!leftAns && rightAns)
            return rightAns;
        return leftAns;
    }
    
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,bool>vist;
        unordered_map<TreeNode*,TreeNode*>parent;
        populateParent(root,NULL,parent);
        TreeNode* startNode = findStartNode(root,start);
        
        return timeRequired(startNode,parent,vist)-1;
    }
};
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
    
    void findDepthAndParent(TreeNode* root, int currentDepth, int currentParent, int x, int y,
                           vector<int>&depth, vector<int>&parent)
    {
        if(root == NULL)
            return;
        
        if(root->val == x)
        {
            depth[0] = currentDepth;
            parent[0] = currentParent;
        }
        
        if(root->val == y)
        {
            depth[1] = currentDepth;
            parent[1] = currentParent;
        }
        
        findDepthAndParent(root->left,currentDepth+1,root->val,x,y,depth,parent);
        findDepthAndParent(root->right,currentDepth+1,root->val,x,y,depth,parent);
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        vector<int>depth(2,0);
        vector<int>parent(2,0);
        findDepthAndParent(root,0,-1,x,y,depth,parent);
        
        return depth[0] == depth[1] && parent[0] != parent[1];
    }
};
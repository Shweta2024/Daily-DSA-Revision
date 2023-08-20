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
    
    bool isUnival(TreeNode* root, int target)
    {
        if(root == NULL) return true;
        if(root->val != target) return false;
        
        bool leftAns = isUnival(root->left,target);
        bool rightAns = isUnival(root->right,target);
        
        return leftAns && rightAns;
    }
    
    bool isUnivalTree(TreeNode* root) 
    {
        if(root == NULL) return true;
        
        return isUnival(root,root->val);
    }
};
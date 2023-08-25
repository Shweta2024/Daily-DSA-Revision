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
    
    bool isPathSumPresent(TreeNode* root, int target)
    {
        if(!root->left && !root->right)
        {
            if(target == 0)
                return true;
            return false;
        }
        
        bool leftAns = false, rightAns = false;
        
        if(root->left)
            leftAns = isPathSumPresent(root->left,target-root->left->val);
        if(root->right)
            rightAns = isPathSumPresent(root->right,target-root->right->val);
        
        return leftAns || rightAns;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return false;
        
        return isPathSumPresent(root,targetSum-root->val);
    }
};
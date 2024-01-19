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
    
    int findHeight(TreeNode* root, bool &balance)
    {
        if(!root) return 0;
        
        int leftHeight = findHeight(root->left,balance);
        int rightHeight = findHeight(root->right,balance);
        
        if(abs(leftHeight - rightHeight) > 1)
            balance = false;
        
        return 1+max(leftHeight,rightHeight);
    }
    
    // abs(height of left - height of right) <= 1
    bool isBalanced(TreeNode* root)
    {
        bool balance = true;
        int height = findHeight(root,balance);
        
        return balance;
    }
};
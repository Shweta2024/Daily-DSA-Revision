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
    
    int findSum(TreeNode* root, int low, int high)
    {
        if(root == NULL) return 0;
        
        if(low <= root->val && root->val <= high ) return root->val+ findSum(root->left,low,high)
            +findSum(root->right,low,high);
        
        int leftAns = 0, rightAns = 0;
        if(root->val <= low )
             leftAns = findSum(root->right,low,high);
        if(root->val >= high )
             rightAns = findSum(root->left,low,high);
        
        return leftAns+rightAns;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        return findSum(root,low,high);
    }
};
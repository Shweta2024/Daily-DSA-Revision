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
    
    int findDiameter(TreeNode* root, int &diameter)
    {
        int leftAns = 0;
        int rightAns = 0;
        
        if(root->left)
            leftAns = 1 + findDiameter(root->left,diameter);
        if(root->right)
            rightAns = 1 + findDiameter(root->right,diameter);
        
        diameter = max(diameter,leftAns+rightAns);
        
        return max(leftAns,rightAns);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        
        findDiameter(root,diameter);
        
        return diameter;
    }
};
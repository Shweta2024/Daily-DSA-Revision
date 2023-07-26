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
    
    int maxAmount(TreeNode* root, unordered_map<TreeNode*,int>&memo)
    {
        if(root == NULL)
            return 0; // no profit
        
        if(memo.find(root) != memo.end())
            return memo[root];
        
        //take
        int take = root->val;
        if(root->left)
        {
            take += maxAmount(root->left->left,memo) +
                       maxAmount(root->left->right,memo);
        }
        if(root->right)
        {
            take += maxAmount(root->right->left,memo) +
                       maxAmount(root->right->right,memo);
        }
        
        //not take
        int notTake = maxAmount(root->left,memo) + maxAmount(root->right,memo);
        
        memo[root] = max(take,notTake);
        return memo[root];
    }
    
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*,int>memo;
        return maxAmount(root,memo);
    }
};
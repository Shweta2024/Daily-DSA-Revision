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
    
    void findRootToLeafSum(TreeNode* root, string path, int &ans)
    {
        // reached a leaf node
        if(root->left == NULL && root->right == NULL)
        {
            int temp = 0;
            if(path.size() != 0)
                temp = stoi(path,0,2);
            ans += temp;
            return ;
        }
        
        if(root->left)
            findRootToLeafSum(root->left,path+to_string(root->left->val),ans);
        
        if(root->right)
            findRootToLeafSum(root->right,path+to_string(root->right->val),ans);
    }
    
    
    int sumRootToLeaf(TreeNode* root) 
    {
        int ans = 0;
        
        findRootToLeafSum(root,""+to_string(root->val),ans);
        
        return ans;
    }
};
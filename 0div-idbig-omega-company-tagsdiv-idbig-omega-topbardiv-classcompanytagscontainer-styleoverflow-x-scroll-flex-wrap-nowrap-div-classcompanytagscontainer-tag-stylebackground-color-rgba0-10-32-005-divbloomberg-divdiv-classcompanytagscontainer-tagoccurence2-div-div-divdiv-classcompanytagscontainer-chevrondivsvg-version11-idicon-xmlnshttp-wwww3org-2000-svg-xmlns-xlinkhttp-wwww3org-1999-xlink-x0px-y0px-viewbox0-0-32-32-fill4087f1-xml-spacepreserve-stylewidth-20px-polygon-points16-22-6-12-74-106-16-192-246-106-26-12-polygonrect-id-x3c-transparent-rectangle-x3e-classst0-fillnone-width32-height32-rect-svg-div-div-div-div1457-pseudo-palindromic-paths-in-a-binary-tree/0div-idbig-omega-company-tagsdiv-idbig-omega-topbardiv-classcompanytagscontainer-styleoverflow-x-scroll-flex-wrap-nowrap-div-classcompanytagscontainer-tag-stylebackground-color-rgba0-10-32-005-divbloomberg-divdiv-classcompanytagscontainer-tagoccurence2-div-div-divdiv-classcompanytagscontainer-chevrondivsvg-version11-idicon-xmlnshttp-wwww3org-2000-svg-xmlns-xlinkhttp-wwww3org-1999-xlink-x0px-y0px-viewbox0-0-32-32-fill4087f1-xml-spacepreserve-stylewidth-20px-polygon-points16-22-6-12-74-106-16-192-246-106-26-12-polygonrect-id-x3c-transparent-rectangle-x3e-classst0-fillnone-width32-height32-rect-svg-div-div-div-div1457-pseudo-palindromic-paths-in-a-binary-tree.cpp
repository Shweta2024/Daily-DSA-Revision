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
    
    bool isPseudoPalindromic(vector<int>& count)
    {   
        int oddFreq = 0;
        for(auto current : count)
        {
            if(current == 0) continue;
            if(current%2 == 1) oddFreq++;
            
            if(oddFreq > 1)
                return false;
        }
        return true;
    }
    
 
    void totalPseudoPalindromicPaths(TreeNode* root, int &ans, vector<int>&count)
    {
        if(root == NULL) return;
        
        count[root->val]++;
        totalPseudoPalindromicPaths(root->left,ans,count);
        totalPseudoPalindromicPaths(root->right,ans,count);
        
        if(!root->left && !root->right)
        {
            if(isPseudoPalindromic(count))
                ans++;
        }
        
        // undo changes
        count[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int ans = 0;
        vector<int>count(10,0);
        
        totalPseudoPalindromicPaths(root,ans,count);        
        
        return ans;
    }
};
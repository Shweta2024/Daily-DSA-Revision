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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == NULL) return {};
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            vector<int>currentLevelNodes;
            while(len--)
            {
                TreeNode* current = q.front();
                q.pop();
                
                currentLevelNodes.push_back(current->val);
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            ans.push_back(currentLevelNodes);
        }
        return ans;
    }
};
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            double sum = 0;
            double nodesInCurrentLevel = len;
            while(len--)
            {
                TreeNode* current = q.front();
                q.pop();
                
                sum += current->val;
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            double average = sum/nodesInCurrentLevel;
            ans.push_back(average);
        }
        return ans;
    }
};
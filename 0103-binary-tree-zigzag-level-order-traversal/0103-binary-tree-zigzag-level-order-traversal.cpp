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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root) return {};
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool reverse = false;
        
        while(!q.empty())
        {
            int len = q.size();
            vector<int>currentLevel(len,0);
            int index = 0;
            if(reverse)
                index = len-1;
            
            while(len--)
            {
                TreeNode* current = q.front();
                q.pop();
                
                currentLevel[index] = current->val;

                if(current->left)
                    q.push({current->left});
                if(current->right)
                    q.push({current->right});
                
                if(reverse)
                    index--;
                else
                    index++;
            }
            ans.push_back(currentLevel);
            reverse = !reverse;
        }
        return ans;
    }
};
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
    int findBottomLeftValue(TreeNode* root) 
    {
        TreeNode* leftMostNode = NULL;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            leftMostNode = q.front();
            
            while(len--)
            {
                TreeNode* currentNode = q.front();
                q.pop();
                
                if(currentNode->left)
                    q.push(currentNode->left);
                if(currentNode->right)
                    q.push(currentNode->right);
            }
        }
        return leftMostNode->val;
    }
};
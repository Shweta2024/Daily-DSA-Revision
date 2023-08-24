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
    
    void findRootToLeafPaths(TreeNode* root, string currentPath, vector<string>&allPaths)
    {
        // got a path
        if(root->left == NULL && root->right == NULL)
        {
            currentPath.pop_back(); // remove the extra "->"
            currentPath.pop_back();
            allPaths.push_back(currentPath);
            return;
        }
        
        if(root->left)
            findRootToLeafPaths(root->left,currentPath+to_string(root->left->val)+"->",allPaths);
        if(root->right)
            findRootToLeafPaths(root->right,currentPath+to_string(root->right->val)+"->",allPaths);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string>allPaths;
        findRootToLeafPaths(root,to_string(root->val)+"->",allPaths);
        return allPaths;
    }
};
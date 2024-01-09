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
    
    void findLeafNodes(TreeNode* root, string &leafNodes)
    {
        if(root->left == NULL && root->right == NULL)
        {
            leafNodes += to_string(root->val) + ":";
            return;
        }
        
        if(root->left)
            findLeafNodes(root->left,leafNodes);
        if(root->right)
            findLeafNodes(root->right,leafNodes);
        
        return ;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        string leafOfR1 = "";
        findLeafNodes(root1,leafOfR1);
        string leafOfR2 = "";
        findLeafNodes(root2,leafOfR2);
        cout<<leafOfR1<<"#"<<leafOfR2<<endl;
        
        return leafOfR1 == leafOfR2;
    }
};
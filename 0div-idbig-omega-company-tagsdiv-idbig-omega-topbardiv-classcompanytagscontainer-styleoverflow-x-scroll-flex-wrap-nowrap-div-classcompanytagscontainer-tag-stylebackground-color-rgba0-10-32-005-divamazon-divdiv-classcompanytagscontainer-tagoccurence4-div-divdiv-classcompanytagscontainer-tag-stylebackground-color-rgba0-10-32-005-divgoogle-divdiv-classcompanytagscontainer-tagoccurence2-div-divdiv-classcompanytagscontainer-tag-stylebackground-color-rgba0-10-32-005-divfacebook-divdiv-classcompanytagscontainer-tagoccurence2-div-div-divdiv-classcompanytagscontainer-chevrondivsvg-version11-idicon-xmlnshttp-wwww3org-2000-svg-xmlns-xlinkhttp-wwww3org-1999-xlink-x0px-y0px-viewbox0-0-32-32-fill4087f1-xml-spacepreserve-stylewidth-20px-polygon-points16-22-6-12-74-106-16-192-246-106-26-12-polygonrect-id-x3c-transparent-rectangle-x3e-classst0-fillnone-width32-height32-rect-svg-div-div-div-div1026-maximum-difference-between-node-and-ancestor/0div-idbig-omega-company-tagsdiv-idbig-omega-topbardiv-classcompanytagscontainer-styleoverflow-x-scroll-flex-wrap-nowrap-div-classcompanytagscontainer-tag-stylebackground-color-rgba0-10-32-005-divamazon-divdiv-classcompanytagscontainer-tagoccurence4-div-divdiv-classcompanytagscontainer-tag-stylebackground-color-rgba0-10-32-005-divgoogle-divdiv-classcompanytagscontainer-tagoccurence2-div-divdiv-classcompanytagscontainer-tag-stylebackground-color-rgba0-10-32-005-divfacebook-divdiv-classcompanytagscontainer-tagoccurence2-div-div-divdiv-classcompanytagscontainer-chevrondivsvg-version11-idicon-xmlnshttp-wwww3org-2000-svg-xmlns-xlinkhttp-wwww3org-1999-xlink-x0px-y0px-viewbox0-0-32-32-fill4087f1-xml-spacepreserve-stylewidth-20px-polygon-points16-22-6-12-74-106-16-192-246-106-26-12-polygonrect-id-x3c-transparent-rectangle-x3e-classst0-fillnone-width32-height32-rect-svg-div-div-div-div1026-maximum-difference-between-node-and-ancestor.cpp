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
    
    void populateAncestor(TreeNode* root, TreeNode* anc, vector<int>current,
                          unordered_map<TreeNode*,vector<int>>&ancestor)
    {
        if(!root) return;
        
        // cout<<root->val<<": ";
        current.push_back(anc->val);
        // for(auto i : current)
        //     cout<<i<<" ,";
        // cout<<endl;
        ancestor[root] = current;
        populateAncestor(root->left,root,current,ancestor);
        
        // current.pop_back();
        populateAncestor(root->right,root,current,ancestor);
        
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        unordered_map<TreeNode*,vector<int>>ancestor;
        vector<int>current;
        populateAncestor(root->left,root,current,ancestor);
        populateAncestor(root->right,root,current,ancestor);
        
        int maxDifference = INT_MIN;
        for(auto current : ancestor)
        {
            // cout<<current.first->val<<" -> ";
            TreeNode* currentNode = current.first;
            for(auto currentAncestor : current.second)
            {
                // cout<<currentAncestor<<" , ";
                int currentDifference = abs(currentNode->val - currentAncestor);
                maxDifference = max(maxDifference,currentDifference);
            }
            // cout<<endl;
        }
        return maxDifference;
    }
};
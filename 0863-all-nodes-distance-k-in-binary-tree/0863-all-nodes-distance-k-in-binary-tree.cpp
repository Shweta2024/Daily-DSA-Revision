/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findNodesAtDistanceK(TreeNode* root, int distance, unordered_map<TreeNode*,TreeNode*>&parent, 
                             vector<int>&ans, unordered_map<TreeNode*,bool>&vist)
    {
        if(!root || vist[root]) 
            return;
        
        if(distance == 0) 
            ans.push_back(root->val);
        
        vist[root] = true;
        findNodesAtDistanceK(root->left,distance-1,parent,ans,vist);
        findNodesAtDistanceK(root->right,distance-1,parent,ans,vist);
        findNodesAtDistanceK(parent[root],distance-1,parent,ans,vist);
    }
    
    void populateParent(TreeNode* current, TreeNode* prev, unordered_map<TreeNode*,TreeNode*>&parent)
    {
        if(!current) return;
        
        parent[current] = prev;
        
        populateParent(current->left,current,parent);
        populateParent(current->right,current,parent);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        populateParent(root,NULL,parent);
        
        unordered_map<TreeNode*,bool>vist;
        findNodesAtDistanceK(target,k,parent,ans,vist);
        
        return ans;
    }
};
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

    TreeNode* constructTree(int &currentIndex, int inStart, int inEnd, vector<int>&preorder, 
                            vector<int>&inorder, unordered_map<int,int>&memo)
    {
        if(inStart > inEnd || currentIndex == preorder.size()) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[currentIndex]);
        int newNodeIndexInInorder = memo[preorder[currentIndex]]; // gives index of newNode in inorder
        currentIndex++;
        
        newNode->left = constructTree(currentIndex,inStart,newNodeIndexInInorder-1,preorder,inorder,memo);
        newNode->right = constructTree(currentIndex,newNodeIndexInInorder+1,inEnd,preorder,inorder,memo);
        
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>memo;
        for(int index = 0; index < inorder.size(); index++)
            memo[inorder[index]] = index;
        
        int currentIndex = 0;
        TreeNode* root = constructTree(currentIndex,0,inorder.size()-1,preorder,inorder,memo);
        
        return root;
    }
};
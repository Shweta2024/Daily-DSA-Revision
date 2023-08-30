//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/


Node* constructTree(int &currentIndex, int inStart, int inEnd, int postorder[], int inorder[], 
                    unordered_map<int,int>&memo)
{
    if(inStart > inEnd || currentIndex < 0) return NULL;
    
    Node* root = new Node(postorder[currentIndex]);
    int rootIndexInInorder = memo[postorder[currentIndex]];
    currentIndex--;
    
    root->right = constructTree(currentIndex,rootIndexInInorder+1,inEnd,postorder,inorder,memo);
    root->left = constructTree(currentIndex,inStart,rootIndexInInorder-1,postorder,inorder,memo);
    
    return root;
}



//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) 
{
    int currentIndex = n-1;
    unordered_map<int,int>memo;
    for(int index = 0; index < n; index++)
        memo[in[index]] = index;
        
    Node* root = constructTree(currentIndex,0,n-1,post,in,memo);
    
    return root;
}

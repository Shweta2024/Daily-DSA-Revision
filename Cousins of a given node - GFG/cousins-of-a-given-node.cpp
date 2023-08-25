//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

Node* pointer(Node* root, int n)
{
	if (root == NULL)
		return NULL;

	if (root->data == n)
		return root;

	Node* l = pointer(root->left, n);
	if (l != NULL && l->data == n)
		return l;

	Node* r = pointer(root->right, n);
	return r;

}


// } Driver Code Ends
//User function Template for C++

/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int>ans;
        vector<vector<pair<Node*,Node*>>>levelOrder;
        queue<pair<Node*,Node*>>q;
        q.push({root,NULL});
        bool found = false;
        Node* targetParent = NULL;
        
        while(!q.empty())
        {
            int len = q.size();
            vector<pair<Node*,Node*>>currentLevel;
            while(len--)
            {
                Node* current = q.front().first;
                Node* parent = q.front().second;
                q.pop();
                
                if(current == node_to_find)
                {
                    found = true;
                    targetParent = parent;
                }
                
                currentLevel.push_back({current,parent});
                
                if(current->left)
                    q.push({current->left,current});
                if(current->right)
                    q.push({current->right,current});
                
            }
            levelOrder.push_back(currentLevel);
            if(found)
                break;
        }
        for(auto current : levelOrder[levelOrder.size()-1])
        {
            if(current.first != node_to_find && current.second != targetParent)
                ans.push_back(current.first->data);
        } 
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		int n;
		cin >> n;
		getchar();

		string inp;
		getline(cin, inp);
		
		struct Node* root = buildTree(inp);

		Node* p = pointer(root, n);

        Solution ob;
		vector<int> ans = ob.printCousins(root, p);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";


	}

	return 0;
}


// } Driver Code Ends
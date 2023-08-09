//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    bool dfs(int currentNode, vector<bool>&vist, vector<bool>&anc, vector<int>adj[], vector<int>&ans)
    {
        vist[currentNode] = true;
        anc[currentNode] = true;
        
        //process adj
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
            {
                //cycle exists
                if(dfs(adjacentNode,vist,anc,adj,ans))
                    return true;
            }
            //cycle exists
            else if(anc[adjacentNode] == true)
                return true;
        }
        //undo
        anc[currentNode] = false;
        
        //add currentNode to ans
        ans.push_back(currentNode);
        return false;
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    vector<bool>vist(V,false);
	    vector<bool>anc(V,false);
	    
	    for(int currentNode = 0; currentNode < V; currentNode++)
	    {
	        if(!vist[currentNode])
	        {
	            //graph exists: so we won't get any topo order
	            if(dfs(currentNode,vist,anc,adj,ans))
	                return {};
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
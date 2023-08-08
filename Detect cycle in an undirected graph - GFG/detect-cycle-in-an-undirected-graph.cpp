//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool dfs(int currentNode, int parent, vector<bool>&vist, vector<int> adj[])
  {
      vist[currentNode] = true;
      
      //process adj
      for(auto adjacentNode : adj[currentNode])
      {
          if(!vist[adjacentNode])
          {
              if(dfs(adjacentNode,currentNode,vist,adj))
                return true;
          }
          
          //if adjacentNode is already visited & its not a parent of the currentNode
          //then it means that there is a cycle through which we have reached currentNode again
          else if(adjacentNode != parent)
            return true;
      }
      return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>vist(V,false);
        
        for(int currentNode = 0; currentNode < V; currentNode++)
        {
            if(!vist[currentNode])
            {
                if(dfs(currentNode,-1,vist,adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
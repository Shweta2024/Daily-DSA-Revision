//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool dfs(int currentNode, vector<bool>&vist, vector<bool>&anc, vector<int> adj[])
  {
      vist[currentNode] = true;
      anc[currentNode] = true;
      
      for(auto adjacentNode : adj[currentNode])
      {
          if(!vist[adjacentNode])
          {
              if(dfs(adjacentNode,vist,anc,adj))
              return true;
          }
          else if(anc[adjacentNode])
          return true;
      }
      anc[currentNode] = false;
      return false;
  }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool>vist(V,false);
        vector<bool>anc(V,false);
        
        for(int currentNode = 0; currentNode < V; currentNode++)
        {
            if(!vist[currentNode])
            {
                if(dfs(currentNode,vist,anc,adj))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
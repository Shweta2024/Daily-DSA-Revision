//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(int currentNode, vector<bool>&visit, vector<int>&ans, vector<int> adj[])
  {
      visit[currentNode] = true;
      ans.push_back(currentNode);
      
      //process adjacentNodes
      for(auto adjacentNode : adj[currentNode])
      {
          if(!visit[adjacentNode])
            dfs(adjacentNode,visit,ans,adj);
      }
  }
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<bool>visit(V,false);
        vector<int>ans;
        
        // since we can have a disconnected graph
        for(int currentNode = 0; currentNode < V; currentNode++)
        {   
            if(!visit[currentNode])
                dfs(currentNode,visit,ans,adj);
        }
        
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
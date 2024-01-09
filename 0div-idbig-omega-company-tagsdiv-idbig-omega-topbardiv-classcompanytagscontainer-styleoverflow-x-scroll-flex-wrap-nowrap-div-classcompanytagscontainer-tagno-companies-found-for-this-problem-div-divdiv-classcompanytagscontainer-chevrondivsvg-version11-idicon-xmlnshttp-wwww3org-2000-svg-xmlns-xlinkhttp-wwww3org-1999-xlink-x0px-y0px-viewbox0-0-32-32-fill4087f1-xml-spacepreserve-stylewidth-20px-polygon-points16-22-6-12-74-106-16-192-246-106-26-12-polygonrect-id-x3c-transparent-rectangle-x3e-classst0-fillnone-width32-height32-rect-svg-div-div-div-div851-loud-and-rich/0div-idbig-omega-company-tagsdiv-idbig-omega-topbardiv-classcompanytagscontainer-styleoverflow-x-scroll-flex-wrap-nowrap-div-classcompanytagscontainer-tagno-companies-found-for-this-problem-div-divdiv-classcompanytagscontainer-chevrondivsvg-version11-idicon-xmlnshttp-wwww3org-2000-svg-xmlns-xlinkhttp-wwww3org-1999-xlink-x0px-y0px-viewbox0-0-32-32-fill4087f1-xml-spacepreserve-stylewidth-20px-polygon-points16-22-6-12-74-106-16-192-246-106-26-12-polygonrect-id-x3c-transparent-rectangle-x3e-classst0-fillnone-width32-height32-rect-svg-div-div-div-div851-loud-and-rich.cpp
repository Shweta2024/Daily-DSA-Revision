class Solution {
public:
    
    void dfs(int currentNode, int &quietestNode, vector<bool>&vist, vector<vector<int>>&adj, vector<int>&quiet)
    {
        vist[currentNode] = true;
        
        if(quiet[currentNode] <= quiet[quietestNode])
            quietestNode = currentNode;
        
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
                dfs(adjacentNode,quietestNode,vist,adj,quiet);
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        int n = quiet.size();
        vector<int>ans(n,0);
        vector<vector<int>>adj(n);
        for(auto current : richer)
            adj[current[1]].push_back(current[0]);
        
        for(int currentNode = 0; currentNode < n; currentNode++)
        {
            vector<bool>vist(n,false);
            if(!vist[currentNode])
            {
                int quietestNode = currentNode;
                dfs(currentNode,quietestNode,vist,adj,quiet);
                ans[currentNode] = quietestNode;
            }
        }
        return ans;
    }
};
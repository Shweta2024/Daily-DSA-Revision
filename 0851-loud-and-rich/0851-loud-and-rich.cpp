class Solution {
public:
    
    void dfs(int currentNode, int &quietestNode, vector<bool>&vist, vector<int>&quiet, vector<int>adj[])
    {
        vist[currentNode] = true;
        
        if(quiet[currentNode] <= quiet[quietestNode])
            quietestNode = currentNode;
        
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
                dfs(adjacentNode,quietestNode,vist,quiet,adj);
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int n = quiet.size();
        vector<int>ans(n);
        vector<int>adj[n];
        
        for(auto current : richer)
            adj[current[1]].push_back(current[0]);
        
        for(int currentNode = 0; currentNode < n; currentNode++)
        {
            vector<bool>vist(n,false);
            int quietestNode = currentNode;
            dfs(currentNode,quietestNode,vist,quiet,adj);
            ans[currentNode] = quietestNode;
        }
        return ans;
    }
};
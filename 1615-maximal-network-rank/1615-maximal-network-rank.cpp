class Solution {
public:
    
    bool areAdjacent(vector<int>arr, int target)
    {
        for(auto current : arr)
        {
            if(current == target)
                return true;
        }
        return false;
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        int maxRank = 0;
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto current : roads)
        {
            degree[current[0]]++;
            degree[current[1]]++;
            adj[current[0]].push_back(current[1]);
            adj[current[1]].push_back(current[0]);
        }
        
        for(int currentNode = 0; currentNode < n; currentNode++)
        {
            for(int otherNode = currentNode+1; otherNode < n; otherNode++)
            {
                int rank = degree[currentNode] + degree[otherNode];
                
                //if the currentNode & otherNode are adjacent to each other 
                //then it means they have an edge in common
                //so decremet 1 as that edge got counted twice
                if(areAdjacent(adj[currentNode],otherNode))
                    rank -= 1;
                
                maxRank = max(maxRank,rank);
            }
        }
        return maxRank;
    }
};
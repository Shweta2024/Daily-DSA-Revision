class Solution {
public:
    
    void dfs(int currentNode, vector<bool>&vist, vector<vector<int>>&adj)
    {
        vist[currentNode] = true;
        
        //process adj
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
                dfs(adjacentNode,vist,adj);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool>vist(rooms.size(),false);
        
        dfs(0,vist,rooms);
        
        for(auto current : vist)
        {
            if(!current)
                return false;
        }
        return true;
    }
};
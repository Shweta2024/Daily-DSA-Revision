class Solution {
public:
    
    bool bfs(int startNode, int startColor, vector<int>&color, vector<vector<int>>&adj)
    {
        queue<vector<int>>q; //node : color
        color[startNode] = startColor;
        q.push({startNode,startColor});
        
        while(!q.empty())
        {
            int currentNode = q.front()[0];
            int currentColor = q.front()[1];
            q.pop();
            
            //process adj
            for(auto adjacentNode : adj[currentNode])
            {
                if(color[adjacentNode] == -1)
                {
                    color[adjacentNode] = 1-currentColor;
                    q.push({adjacentNode,color[adjacentNode]});
                }
                else if(color[adjacentNode] == color[currentNode])
                    return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<int>color(n+1,-1);
        
        vector<vector<int>>adj(n+1);
        for(auto current : dislikes)
        {
            adj[current[0]].push_back(current[1]);
            adj[current[1]].push_back(current[0]);
        }
        
        for(int currentNode = 1; currentNode <= n; currentNode++)
        {
            int currentColor = 0;
            if(color[currentNode] == -1 && !bfs(currentNode,currentColor,color,adj))
                return false;
        }
        return true;
    }
};
class Solution {
public:
    
    bool canColor(int currentNode, int currentColor, vector<int>&color, vector<vector<int>>&adj)
    {
        //color the currentNode with currentColor
        color[currentNode] = currentColor;
        
        //process its adj
        for(auto adjacentNode : adj[currentNode])
        {
            //check if adjacentNode is colored or not
            //if its not colored, then color it with opp color of the currentNode
            if(color[adjacentNode] == -1)
            {
                if(!canColor(adjacentNode,1-currentColor,color,adj))
                    return false;
            }
            
            //if its colored same as the currentNode, then its not bipartite
            else if(color[adjacentNode] == color[currentNode])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>color(n,-1);
        
        // since it can be a disconnected graph
        for(int currentNode = 0; currentNode < n; currentNode++)
        {
            int currentColor = 0;
            if(color[currentNode] == -1 && !canColor(currentNode,currentColor,color,graph))
                return false;
        }
        return true;
    }
};
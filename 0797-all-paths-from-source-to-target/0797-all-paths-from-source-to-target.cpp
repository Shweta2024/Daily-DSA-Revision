class Solution {
public:
    
    void findAllPaths(int currentNode, int targetNode, vector<int>currentAns, vector<vector<int>>&ans, 
                      vector<bool>vist, vector<vector<int>>& adj)
    {
        //got a path
        if(currentNode == targetNode)
        {
            currentAns.push_back(targetNode);
            ans.push_back(currentAns);
            return;
        }
        
        //mark as visited
        vist[currentNode] = true;
        currentAns.push_back(currentNode);
        
        //process adj
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
                findAllPaths(adjacentNode,targetNode,currentAns,ans,vist,adj);
        
        }
        return ;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>>ans;
        vector<int>currentAns;
        vector<bool>vist(graph.size(),false);
        
        findAllPaths(0,graph.size()-1,currentAns,ans,vist,graph);
        
        return ans;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int>ans;
        vector<int>indegree(n,0);
        
        for(auto current : edges)
            indegree[current[1]]++;
        
        for(int currentNode = 0; currentNode < n; currentNode++)
        {
            if(indegree[currentNode] == 0)
                ans.push_back(currentNode);
        }
        return ans;
    }
};
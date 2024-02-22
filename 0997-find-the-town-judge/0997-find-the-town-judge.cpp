class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        
        for(auto current : trust)
        {
            int from = current[0];
            int to = current[1];
            outdegree[from]++;
            indegree[to]++;
        }
        for(int currentNode = 1; currentNode <= n; currentNode++)
        {
            if(outdegree[currentNode] == 0 && indegree[currentNode] == n-1)
                return currentNode;
        }
        return -1;
    }
};
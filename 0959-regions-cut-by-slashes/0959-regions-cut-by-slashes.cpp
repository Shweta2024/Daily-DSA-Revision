class Solution {
public:
    
    void dfs(int currentRow, int currentCol, int m, vector<vector<int>>&graph)
    {
        if(currentRow < 0 || currentCol < 0 || currentRow >= m || currentCol >= m || 
           graph[currentRow][currentCol] == 1)
            return ;
        
        //mark visited
        graph[currentRow][currentCol] = 1;
        
        //process adj
        dfs(currentRow+1,currentCol,m,graph);
        dfs(currentRow-1,currentCol,m,graph);
        dfs(currentRow,currentCol+1,m,graph);
        dfs(currentRow,currentCol-1,m,graph);        
    }
    
    void constructGraph(vector<vector<int>>&graph, vector<string>&grid)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if(grid[i][j] == '/')
                {
                    graph[i*3][j*3+2] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\')
                {
                    graph[i*3][j*3] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3+2][j*3+2] = 1;
                }
            }
        }
    }
    
    int regionsBySlashes(vector<string>& grid) 
    {
        int totalRegion = 0;
        int n = grid.size();
        vector<vector<int>>graph(n*3,vector<int>(n*3,0));
        constructGraph(graph,grid);
        
        int m = n*3;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(graph[i][j] == 0)
                {
                    dfs(i,j,m,graph);
                    totalRegion++;
                }
            }
        }
        return totalRegion;
    }
};
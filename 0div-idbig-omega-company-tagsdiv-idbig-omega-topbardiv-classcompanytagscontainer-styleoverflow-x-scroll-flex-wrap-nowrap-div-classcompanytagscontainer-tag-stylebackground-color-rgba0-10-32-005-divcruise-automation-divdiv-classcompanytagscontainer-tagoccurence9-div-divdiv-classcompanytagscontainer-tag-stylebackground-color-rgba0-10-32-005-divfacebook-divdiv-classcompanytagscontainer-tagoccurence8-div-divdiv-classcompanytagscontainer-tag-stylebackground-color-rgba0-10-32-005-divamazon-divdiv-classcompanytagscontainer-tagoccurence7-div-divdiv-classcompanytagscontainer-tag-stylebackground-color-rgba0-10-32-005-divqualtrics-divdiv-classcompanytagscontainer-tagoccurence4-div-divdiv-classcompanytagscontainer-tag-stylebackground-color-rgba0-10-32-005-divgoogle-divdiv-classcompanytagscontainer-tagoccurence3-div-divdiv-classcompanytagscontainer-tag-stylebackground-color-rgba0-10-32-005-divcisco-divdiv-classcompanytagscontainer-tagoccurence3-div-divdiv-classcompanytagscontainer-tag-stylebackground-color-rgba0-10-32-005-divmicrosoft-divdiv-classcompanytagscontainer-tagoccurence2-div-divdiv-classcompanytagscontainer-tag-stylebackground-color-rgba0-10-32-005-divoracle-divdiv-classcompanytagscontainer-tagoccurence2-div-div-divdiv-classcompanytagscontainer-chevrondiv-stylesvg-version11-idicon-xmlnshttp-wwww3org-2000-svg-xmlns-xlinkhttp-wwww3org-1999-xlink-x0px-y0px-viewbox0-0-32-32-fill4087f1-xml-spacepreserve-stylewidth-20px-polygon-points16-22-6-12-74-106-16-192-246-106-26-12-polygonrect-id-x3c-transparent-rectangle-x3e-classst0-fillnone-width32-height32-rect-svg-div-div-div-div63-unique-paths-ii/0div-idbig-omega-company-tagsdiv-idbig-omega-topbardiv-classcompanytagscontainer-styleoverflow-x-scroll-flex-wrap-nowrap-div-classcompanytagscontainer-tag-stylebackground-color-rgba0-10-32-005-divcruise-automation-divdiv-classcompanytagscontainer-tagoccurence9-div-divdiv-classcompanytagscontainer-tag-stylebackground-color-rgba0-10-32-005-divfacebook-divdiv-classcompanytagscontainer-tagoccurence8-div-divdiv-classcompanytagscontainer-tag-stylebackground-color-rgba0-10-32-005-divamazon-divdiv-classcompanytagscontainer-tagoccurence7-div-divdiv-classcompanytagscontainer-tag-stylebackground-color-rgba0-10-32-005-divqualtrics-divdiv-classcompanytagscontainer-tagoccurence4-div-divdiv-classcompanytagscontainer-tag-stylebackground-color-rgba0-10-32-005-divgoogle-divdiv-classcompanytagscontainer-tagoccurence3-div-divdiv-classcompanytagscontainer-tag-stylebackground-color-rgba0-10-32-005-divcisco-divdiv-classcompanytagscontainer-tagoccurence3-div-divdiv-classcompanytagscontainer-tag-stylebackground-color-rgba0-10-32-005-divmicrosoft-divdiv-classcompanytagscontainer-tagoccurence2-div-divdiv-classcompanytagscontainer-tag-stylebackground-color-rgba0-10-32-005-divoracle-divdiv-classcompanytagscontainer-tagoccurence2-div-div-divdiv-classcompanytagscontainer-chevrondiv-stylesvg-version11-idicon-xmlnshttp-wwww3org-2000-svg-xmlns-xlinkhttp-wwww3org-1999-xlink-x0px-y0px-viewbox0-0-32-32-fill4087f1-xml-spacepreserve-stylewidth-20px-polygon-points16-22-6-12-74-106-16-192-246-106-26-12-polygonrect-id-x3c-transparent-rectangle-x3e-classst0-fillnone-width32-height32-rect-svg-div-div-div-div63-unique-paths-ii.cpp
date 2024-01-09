class Solution {
public:
    
    int totalWays(int currentRow, int currentCol, int totalRow, int totalCol, vector<vector<int>>&grid,
                 vector<vector<int>>&memo)
    {
        if(currentRow > totalRow || currentCol > totalCol || grid[currentRow][currentCol] == 1) return 0;
        if(currentRow == totalRow && currentCol == totalCol) return 1;
        if(memo[currentRow][currentCol] != -1) return memo[currentRow][currentCol];
        
        int down = totalWays(currentRow+1,currentCol,totalRow,totalCol,grid,memo);
        int right = totalWays(currentRow,currentCol+1,totalRow,totalCol,grid,memo);
        
        memo[currentRow][currentCol] = down+right;
        return memo[currentRow][currentCol];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return totalWays(0,0,n-1,m-1,grid,memo);
    }
};
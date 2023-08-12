class Solution {
public:
    
    int totalWays(int currentRow, int currentCol, int targetRow, int targetCol, vector<vector<int>>&grid,
                  vector<vector<int>>&memo)
    {
        // valid path
        if(currentRow == targetRow && currentCol == targetCol && grid[currentRow][currentCol] != 1)
            return 1;
        
        // invalid path
        if(currentRow > targetRow || currentCol > targetCol || grid[currentRow][currentCol] == 1)
            return 0;
        
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        
        //explore the options
        int down = 0;
        int right = 0;
        //down
        down = totalWays(currentRow+1,currentCol,targetRow,targetCol,grid,memo);
        
        //right
        right = totalWays(currentRow,currentCol+1,targetRow,targetCol,grid,memo);
        
        memo[currentRow][currentCol] = down+right;
        return memo[currentRow][currentCol];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        vector<vector<int>>memo(totalRow,vector<int>(totalCol,-1));
        return totalWays(0,0,totalRow-1,totalCol-1,grid,memo);
    }
};
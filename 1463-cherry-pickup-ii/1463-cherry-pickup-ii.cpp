class Solution {
public:
    vector<int>dx = {-1,1,0};
    
    int maxPickup(int currentRow, int currentCol1, int currentCol2, int n, int m, vector<vector<int>>&grid,
                 vector<vector<vector<int>>>&memo)
    {
        if(currentRow < 0 || currentCol1 < 0 || currentCol2 < 0 || currentRow >= n || currentCol1 >= m || currentCol2 >=m)
            return 0;
        
        if(memo[currentRow][currentCol1][currentCol2] != -1) return memo[currentRow][currentCol1][currentCol2];
        
        int ans = 0;
        if (currentCol1 == currentCol2) ans= grid[currentRow][currentCol1];
        
        if(currentCol1 != currentCol2) ans= grid[currentRow][currentCol1] + grid[currentRow][currentCol2];
        
        int temp = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
                temp = max(temp,maxPickup(currentRow+1,currentCol1+dx[i],currentCol2+dx[j],n,m,grid,memo));
        }
        
        ans += temp;
        return memo[currentRow][currentCol1][currentCol2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return maxPickup(0,0,m-1,n,m,grid,memo);
    }
};
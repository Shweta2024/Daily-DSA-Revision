class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int totalRows = mat.size();
        int totalCols = mat[0].size();
        vector<vector<int>>ans(totalRows,vector<int>(totalCols,0));
        queue<pair<int,int>>q;
    
        for(int i = 0; i < totalRows; i++)
        {
            for(int j = 0; j < totalCols; j++)
            {
                if(mat[i][j] == 0)
                    q.push({i,j});
                if(mat[i][j] == 1)
                    ans[i][j] = INT_MAX;
            }
        }
        
        vector<int>dr = {1,-1,0,0};
        vector<int>dc = {0,0,-1,1};
        
        while(!q.empty())
        {
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();
            
            //process adj
            for(int index = 0; index < 4; index++)
            {
                if(currentRow+dr[index] < 0 || currentRow+dr[index] >= totalRows || 
                   currentCol+dc[index] < 0 || currentCol+dc[index] >= totalCols || 
                  mat[currentRow+dr[index]][currentCol+dc[index]] == 0 || 
                  ans[currentRow+dr[index]][currentCol+dc[index]] <= 1+ans[currentRow][currentCol])
                    continue;
                
                ans[currentRow+dr[index]][currentCol+dc[index]] = 1+ans[currentRow][currentCol];
                q.push({currentRow+dr[index],currentCol+dc[index]});
            }
        }
        return ans;
    }
};
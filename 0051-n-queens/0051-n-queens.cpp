class Solution {
public:
    
    bool isDiagonalValid(int currentRow, int currentCol, vector<string>& board, int n)
    {
        int row = currentRow;
        int col = currentCol;
        
        //upper left
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        row = currentRow;
        col = currentCol;
        
        //upper right
        while(row >= 0 && col < n)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col++;
        }
        return true;
    }
    
    bool isColValid(int currentCol, vector<string>& board, int n)
    {
        for(int currentRow = 0; currentRow < n; currentRow++)
        {
            if(board[currentRow][currentCol] == 'Q')
                return false;
        }
        return true;
    }
    
    
    bool isRowValid(int currentRow, vector<string>& board, int n)
    {
        for(int currentCol = 0; currentCol < n; currentCol++)
        {
            if(board[currentRow][currentCol] == 'Q')
                return false;
        }
        return true;
    }
    
    
    void solve(int currentRow, int n, vector<string>&board, vector<vector<string>>& ans)
    {
        //got an answer
        if(currentRow == n)
        {
            ans.push_back(board);
            return;
        }
        
        //explore all cells of currentRow
        for(int currentCol = 0; currentCol < n; currentCol++)
        {
            if(isRowValid(currentRow,board,n) &&
              isColValid(currentCol,board,n) &&
              isDiagonalValid(currentRow,currentCol,board,n))
            {
                board[currentRow][currentCol] = 'Q';
                
                //move to next row
                solve(currentRow+1,n,board,ans);
                
                //undo
                board[currentRow][currentCol] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        string current(n,'.');
        vector<string>board(n,current);
        
        solve(0,n,board,ans);
        
        return ans;
    }
};
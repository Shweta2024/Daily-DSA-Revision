class Solution {
public:
    
    bool dfs(int currentRow, int currentCol, int currentIndex, string word, vector<vector<char>>& board)
    {
        //got word in board
        if(currentIndex == word.size())
            return true;
        
        //invalid 
        if(currentRow < 0 || currentCol < 0 || currentRow >= board.size() || currentCol >= board[0].size() ||
          board[currentRow][currentCol] != word[currentIndex])
            return false;
    
        //mark as visited
        board[currentRow][currentCol] = '.';
        
        //process adjacent
        bool ans = dfs(currentRow+1,currentCol,currentIndex+1,word,board);
        ans = ans || dfs(currentRow-1,currentCol,currentIndex+1,word,board);
        ans = ans || dfs(currentRow,currentCol+1,currentIndex+1,word,board);
        ans = ans || dfs(currentRow,currentCol-1,currentIndex+1,word,board);
        
        //undo
        board[currentRow][currentCol] = word[currentIndex];
        
        return ans;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int currentRow = 0; currentRow < board.size(); currentRow++)
        {
            for(int currentCol = 0; currentCol < board[0].size(); currentCol++)
            {
                if(board[currentRow][currentCol] == word[0])
                {
                    if(dfs(currentRow,currentCol,0,word,board))
                        return true;
                }
            }
        }
        return false;
    }
};
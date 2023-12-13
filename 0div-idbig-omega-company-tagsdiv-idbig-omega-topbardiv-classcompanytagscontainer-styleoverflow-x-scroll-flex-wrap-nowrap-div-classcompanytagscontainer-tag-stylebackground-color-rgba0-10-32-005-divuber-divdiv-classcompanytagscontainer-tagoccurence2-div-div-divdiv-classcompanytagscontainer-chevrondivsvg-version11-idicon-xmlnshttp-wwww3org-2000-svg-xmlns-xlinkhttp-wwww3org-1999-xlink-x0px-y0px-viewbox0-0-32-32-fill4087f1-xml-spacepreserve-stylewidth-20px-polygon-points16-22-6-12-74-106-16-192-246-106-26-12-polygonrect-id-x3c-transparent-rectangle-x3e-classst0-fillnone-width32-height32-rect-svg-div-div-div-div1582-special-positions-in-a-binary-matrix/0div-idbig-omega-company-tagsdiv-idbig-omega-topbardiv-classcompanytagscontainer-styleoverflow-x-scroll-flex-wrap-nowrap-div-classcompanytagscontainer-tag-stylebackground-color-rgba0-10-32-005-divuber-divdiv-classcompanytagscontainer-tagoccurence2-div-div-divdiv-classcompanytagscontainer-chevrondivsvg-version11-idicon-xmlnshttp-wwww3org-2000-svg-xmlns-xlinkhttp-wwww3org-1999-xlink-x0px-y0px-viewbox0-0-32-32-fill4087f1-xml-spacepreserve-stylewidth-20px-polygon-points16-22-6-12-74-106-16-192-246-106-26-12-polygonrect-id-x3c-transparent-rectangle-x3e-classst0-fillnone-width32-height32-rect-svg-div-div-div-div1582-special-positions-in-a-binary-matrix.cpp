class Solution {
public:
    
    bool isRowValid(int row, int currentCol, vector<vector<int>>& mat)
    {
        for(int col = 0; col < mat[0].size(); col++)
        {
            if(col != currentCol && mat[row][col] == 1)
                return false;
        }
        return true;
    }
    
    bool isColValid(int currentRow, int col, vector<vector<int>>& mat)
    {
        for(int row = 0; row < mat.size(); row++)
        {
            if(row != currentRow && mat[row][col] == 1)
                return false;
        }
        return true;
    }
    
    int numSpecial(vector<vector<int>>& mat)
    {
        int count = 0;
        for(int row = 0; row < mat.size(); row++)
        {
            for(int col = 0; col < mat[0].size(); col++)
            {
                if(mat[row][col] == 1 && isRowValid(row,col,mat) && isColValid(row,col,mat))
                    count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) 
            if(board[x][j] == val) 
                return false;
        
        for(int y=0; y<9; y++) 
            if(board[i][y] == val) 
                return false;
        
        for(int x=0; x<3; x++)
            for(int y=0; y<3; y++)
                if(board[row+x][column+y] == val) 
                    return false;
        return true;
    }
    
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) 
            return true;
        if(j==9) 
            return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') 
            return solveSudoku(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
};
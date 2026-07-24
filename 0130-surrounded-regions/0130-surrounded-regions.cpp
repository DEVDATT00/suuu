class Solution {
    bool c(int i, int j, int rows, int cols) {
        if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
            return true;
        }
        return false;
    }
    void dothat(vector<vector<char>>& board,int rows , int cols , int i , int j,vector<vector<bool>>&check ){
        if(i < 0 || j < 0 || i >= rows || j >= cols){
            return;
        }
        if(!check [i][j] ||board[i][j] == 'X'){
            return;
        }
        check[i][j] = false;
        dothat(board,rows,cols,i+1,j,check);
        dothat(board,rows,cols,i,j+1,check);
        dothat(board,rows,cols,i,j-1,check);
        dothat(board,rows,cols,i-1,j,check);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>>check(rows,vector<bool>(cols,true));
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(c(i,j,rows,cols) && board[i][j] == 'O'){
                    dothat(board,rows,cols,i,j,check);
                }
            }
        }
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(board[i][j] == 'O' && check[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
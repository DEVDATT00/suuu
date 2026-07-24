class Solution {
    bool c(int i , int j , int rows , int cols){
        if(i == 0 || j == 0 || i == rows-1 || j == cols-1){
            return true;
        }
        return false;
    }
    void dothat(vector<vector<int>>& grid,int rows , int cols , int i , int j , int &countones){
        if(i < 0 || j < 0 || i >= rows || j >= cols){
            return;
        }
        if(!grid[i][j]){
            return;
        }
        grid[i][j] = 0;
        countones--;
        dothat(grid,rows,cols,i+1,j,countones);
        dothat(grid,rows,cols,i,j+1,countones);
        dothat(grid,rows,cols,i,j-1,countones);
        dothat(grid,rows,cols,i-1,j,countones);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int countones = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j]){
                    countones++;
                }
            }
        }
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(c(i,j,rows,cols) && grid[i][j]){
                    dothat(grid,rows,cols,i,j,countones);
                }
            }
        }
        return countones;
    }
};
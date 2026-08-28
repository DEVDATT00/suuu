class Solution {
    int find(vector<vector<int>>& grid,int i , int j , int row , int col , int total){
        
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0)
            return total;
        
        int countgold = grid[i][j];
        
        total += grid[i][j];
        
        grid[i][j] = 0;
        
        int left = find(grid,i,j-1,row,col,total);
        int right = find(grid,i+1,j,row,col,total);
        int up = find(grid,i-1,j,row,col,total);
        int down = find(grid,i,j+1,row,col,total);
        
        grid[i][j] = countgold;

        return max(max(left,right),max(up,down));
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maximum = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j])
                    maximum = max(maximum,find(grid,i,j,row,col,0));
            }
        }
        return maximum;
    }
};
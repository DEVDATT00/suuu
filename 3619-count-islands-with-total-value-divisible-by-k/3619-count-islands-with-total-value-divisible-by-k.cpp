class Solution {
    long long dfs(vector<vector<int>>&grid,int i , int j , int r , int c){
        if(i >= r || j >= c || i < 0 || j < 0 || grid[i][j] == 0)
            return 0;
        long long count = grid[i][j];
        grid[i][j] = 0;
        count += dfs(grid,i+1,j,r,c);
        count += dfs(grid,i-1,j,r,c);
        count += dfs(grid,i,j+1,r,c);
        count += dfs(grid,i,j-1,r,c);
        return count;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0; j < col ; j++){
                if(grid[i][j] != 0){
                    long long sum = dfs(grid,i,j,row,col);
                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
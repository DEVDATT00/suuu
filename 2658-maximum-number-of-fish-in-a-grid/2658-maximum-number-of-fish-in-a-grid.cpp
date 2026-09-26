class Solution {
    int checkit(vector<vector<int>>&nums , int i , int j , int row , int col ){
        if(i >= row || j >= col || i < 0 || j < 0 || nums[i][j] == 0)
            return 0;
        int count = nums[i][j];
        nums[i][j] = 0;
        count += checkit(nums,i+1,j,row,col);
        count += checkit(nums,i-1,j,row,col);
        count += checkit(nums,i,j+1,row,col);
        count += checkit(nums,i,j-1,row,col);
        return count;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int mx = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] != 0){
                    mx = max(mx,checkit(grid,i,j,row,col));
                }
            }
        }
        return mx;
    }
};
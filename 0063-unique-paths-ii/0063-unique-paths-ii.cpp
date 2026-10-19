class Solution {
    int killemotion(vector<vector<int>>& nums , vector<vector<int>>& dp , int i , int j , int row , int col){
        if(i > row || j > col || i < 0 || j < 0 || nums[i][j] == 1)
            return 0;
        if(i == row && j == col)
            return dp[i][j] = 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int count = 0;
        count += killemotion(nums, dp , i + 1 , j , row , col);
        count += killemotion(nums, dp , i , j + 1 , row , col);
        return dp[i][j] = count;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return killemotion(obstacleGrid,dp,0,0,row - 1,col - 1);
    }
};
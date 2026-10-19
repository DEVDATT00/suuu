class Solution {
    int killemotion(int i , int j , int row , int col ,vector<vector<int>>&dp){
        if(i > row || j > col || i < 0 || j < 0)
            return 0;
        if(i == row && j == col)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int count = 0;
        count += killemotion(i + 1 , j , row , col , dp);
        count += killemotion(i , j + 1 , row , col , dp);
        return dp[i][j] = count;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return killemotion(0,0,m-1,n-1,dp) % 2000000000;
    }
};
class Solution {
    int find(vector<vector<int>>& grid , int m , int n , int i , int j , vector<vector<int>>&dp){
        if(i >= m || j >= n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == m - 1 && j == n - 1)
            return dp[i][j] = grid[i][j];
        return dp[i][j] = grid[i][j] + min(find(grid,m,n,i+1,j,dp),find(grid,m,n,i,j+1,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find(grid,m,n,0,0,dp);
    }
};
class Solution {
    int killemotions(vector<vector<int>>& nums, vector<vector<int>>& dp, int i,int j, int row, int col) {
        if (i >= row || j >= col)
            return INT_MAX;
        if (i == row - 1 && j == col - 1)
            return dp[i][j] = max(1, 1 - nums[i][j]);
        if (dp[i][j] != -1)
            return dp[i][j];
        int count = min(killemotions(nums, dp, i + 1, j, row, col), killemotions(nums, dp, i, j + 1, row, col));
        return dp[i][j] = max(1, count - nums[i][j]);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return killemotions(dungeon, dp, 0, 0, row, col);
    }
};
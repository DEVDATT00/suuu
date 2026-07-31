class Solution {
    int justdothat(vector<vector<int>>& triangle, int row, int index, vector<vector<int>>& dp) {

        if (row == triangle.size() - 1)
            return triangle[row][index];

        if (dp[row][index] != INT_MAX)
            return dp[row][index];

        int left = justdothat(triangle, row + 1, index, dp);
        int right = justdothat(triangle, row + 1, index + 1, dp);

        return dp[row][index] = triangle[row][index] + min(left, right);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return justdothat(triangle, 0, 0, dp);
    }
};
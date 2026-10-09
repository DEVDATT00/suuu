class Solution {
    int killemotions(int i, int j, int mx, int currmoves, int row, int col,vector<vector<vector<int>>>& dp , int MOD) {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return 1;
        if (currmoves == mx)
            return 0;
        if (dp[i][j][currmoves] != -1)
            return dp[i][j][currmoves];
        long long count = 0;
        count =(count + killemotions(i + 1, j, mx, currmoves + 1, row, col, dp , MOD)) % MOD;
        count =(count + killemotions(i - 1, j, mx, currmoves + 1, row, col, dp , MOD)) % MOD;
        count =(count + killemotions(i, j + 1, mx, currmoves + 1, row, col, dp , MOD)) % MOD;
        count =(count + killemotions(i, j - 1, mx, currmoves + 1, row, col, dp , MOD)) % MOD;
        return dp[i][j][currmoves] = count;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1000000007;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return killemotions(startRow, startColumn, maxMove, 0, m, n, dp , MOD);
    }
};
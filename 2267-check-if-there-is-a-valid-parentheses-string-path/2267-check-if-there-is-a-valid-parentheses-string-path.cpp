class Solution {
    int row, col;
    int dp[100][100][201];
    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {
        if (i >= row || j >= col)
            return false;
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
            return false;
        if (balance > (row - 1 - i) + (col - 1 - j))
            return false;
        if (i == row - 1 && j == col - 1)
            return balance == 0;
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];
        return dp[i][j][balance] = dfs(grid, i + 1, j, balance) || dfs(grid, i, j + 1, balance);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, 0);
    }
};
class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j,int & count) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return ;

        if (grid[i][j] == 0)
            return ;

        if (grid[i][j] == -1)
            return ;

        grid[i][j] = -1;
        count++;

        dfs(grid, i + 1, j,count);
        dfs(grid, i - 1, j,count);
        dfs(grid, i, j + 1,count);
        dfs(grid, i, j - 1,count);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int mx = 0;
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j,count);
                    mx = max(mx,count);
                }
            }
        }
        return mx;
    }
};
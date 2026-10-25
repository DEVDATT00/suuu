class Solution {
    void kill(vector<vector<int>>& grid, int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        kill(grid, i + 1, j, row, col);
        kill(grid, i, j + 1, row, col);
        kill(grid, i - 1, j, row, col);
        kill(grid, i, j - 1, row, col);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            kill(grid, i, 0, row, col);
            kill(grid, i, col - 1, row, col);
        }
        for (int j = 0; j < col; j++) {
            kill(grid, 0, j, row, col);
            kill(grid, row - 1, j, row, col);
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    kill(grid, i, j, row, col);
                }
            }
        }
        return count;
    }
};
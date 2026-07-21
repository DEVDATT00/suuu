
class Solution {
    void mainpart( vector<vector<char>>& grid,int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        mainpart(grid, i - 1, j);
        mainpart(grid, i + 1, j);
        mainpart(grid, i, j - 1);
        mainpart(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    mainpart(grid, i, j);
                }
            }
        }
        return count;
    }
};
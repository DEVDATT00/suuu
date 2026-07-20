class Solution {
    int maintask(vector<vector<bool>>& check, vector<vector<int>>& grid, int i,int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 1;
        }
        if (grid[i][j] == 0 ) {
            return 1;
        }
        if(!check[i][j]){
            return 0;
        }
        check[i][j] = false;
        return maintask(check, grid, i - 1, j)
            +maintask(check, grid, i + 1, j)
            +maintask(check, grid, i, j - 1)
            +maintask(check, grid, i, j + 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int tem;
        vector<vector<bool>> check(grid.size(),vector<bool>(grid[0].size(), true));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    return maintask(check, grid, i, j);
                }
            }
        }
        return 0;
    }
};
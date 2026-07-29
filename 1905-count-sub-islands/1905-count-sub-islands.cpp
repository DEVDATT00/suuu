class Solution {
    int count = 0;
    bool checksubisland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
                        int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return true;

        if (grid2[i][j] == 0)
            return true;
        bool ans = grid1[i][j];
        grid2[i][j] = 0;
        ans &= checksubisland(grid1, grid2, i + 1, j, row, col);
        ans &= checksubisland(grid1, grid2, i, j + 1, row, col);
        ans &= checksubisland(grid1, grid2, i - 1, j, row, col);
        ans &= checksubisland(grid1, grid2, i, j - 1, row, col);
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int row = grid2.size();
        int col = grid2[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid2[i][j] &&
                    checksubisland(grid1, grid2, i, j, row, col)) {
                    count++;
                }
            }
        }
        return count;
    }
};
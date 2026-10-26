class Solution {
public:
    bool kill(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int n, int water) {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return false;
        if (grid[i][j] > water || visited[i][j])
            return false;
        if (i == n - 1 && j == n - 1)
            return true;
        visited[i][j] = 1;
        return kill(grid, visited, i + 1, j, n, water) ||
               kill(grid, visited, i - 1, j, n, water) ||
               kill(grid, visited, i, j + 1, n, water) ||
               kill(grid, visited, i, j - 1, n, water);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max(grid[0][0], grid[n - 1][n - 1]);
        int high = n * n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            vector<vector<int>> visited(n, vector<int>(n, 0));
            if (kill(grid, visited, 0, 0, n, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
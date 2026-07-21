class Solution {
    void change(vector<vector<int>>& grid, int i, int j, int& countf,queue<pair<int, int>>& q) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (countf == 0 || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        q.push({i, j});
        countf--;
    }
    void maintask(vector<vector<int>>& grid, int i, int j, int& countf, queue<pair<int, int>>& q) {
        change(grid, i + 1, j, countf, q);
        change(grid, i - 1, j, countf, q);
        change(grid, i, j + 1, countf, q);
        change(grid, i, j - 1, countf, q);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int countf = 0;
        int sec = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    countf++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (!countf) {
            return 0;
        }
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                maintask(grid, node.first, node.second, countf, q);
            }
            if (!q.empty()) {
                sec++;
            }
        }
        if(countf){
            return -1;
        }
        return sec;
    }
};
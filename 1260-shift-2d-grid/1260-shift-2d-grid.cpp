class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>tem;
        int row = grid.size();
        int coulmns = grid[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < coulmns ; j++){
                tem.push_back(grid[i][j]);
            }
        }
        int t = tem.size();
        int d = t - (k)%t;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < coulmns ; j++){
                grid[i][j] = tem[(d++)%t];
            }
        }
        return grid;
    }
};
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(i == j && grid[i][j] == 0){
                    return false;
                }
                if((i+j) == n - 1 && grid[i][j] == 0){
                    return false;
                }
                if(grid[i][j] != 0 && i != j && (i+j) != n - 1 ){
                    return false;
                }
            }
        }
        return true;
    }
};
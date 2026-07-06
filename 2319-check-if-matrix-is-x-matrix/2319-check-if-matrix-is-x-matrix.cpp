class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        // int n = grid.size();
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(i == j && grid[i][j] == 0){
                    return false;
                }
                if((i+j) == grid.size() - 1 && grid[i][j] == 0){
                    return false;
                }
                if(grid[i][j] != 0 && i != j && (i+j) != grid.size() - 1 ){
                    return false;
                }
            }
        }
        return true;
    }
};
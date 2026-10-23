class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            int start = 0 , end = col - 1;
            int index = col;
            while(start <= end){
                int mid = start + (end - start) / 2;
                if(grid[i][mid] < 0){
                    index = min(index , mid);
                    end = mid - 1;
                }else 
                    start = mid + 1;
            }
            if(index != col)
                count += col - index;
        }
        return count;
    }
};
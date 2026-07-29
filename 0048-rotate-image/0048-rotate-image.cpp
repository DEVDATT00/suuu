class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0 ; 
        int j = matrix.size() - 1;
        while(i < j){
            for(int k = 0 ; k < matrix.size() ; k++){
                swap(matrix[i][k],matrix[j][k]);
            }
            i++;
            j--;
        }
        for(int d = 0 ; d < matrix.size() ; d++){
            for(int s = d + 1 ; s < matrix.size() ; s++){
                swap(matrix[d][s],matrix[s][d]);
            }
        }
    }
};
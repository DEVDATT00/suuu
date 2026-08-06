class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size() == r && mat[0].size() == c)
            return mat;
        int row = mat.size();
        int col = mat[0].size();
        if (row * col != r * c)
            return mat;
        vector<int>tem;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                tem.push_back(mat[i][j]);
            }
        }
        int d = 0;
        vector<vector<int>>ans(r,vector<int>(c));
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ans[i][j] = tem[d++];
            }
        }
        return ans;
    }
};
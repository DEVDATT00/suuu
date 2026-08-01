class Solution {
    vector<int> ans;

    void justdo(vector<vector<int>>& matrix, int r, int c, int rl, int cl) {
        if (r >= rl || c >= cl)
            return;

        for (int j = c; j < cl; j++)
            ans.push_back(matrix[r][j]);

        for (int i = r + 1; i < rl; i++)
            ans.push_back(matrix[i][cl - 1]);

        if (r != rl - 1) {
            for (int j = cl - 2; j >= c; j--)
                ans.push_back(matrix[rl - 1][j]);
        }

        if (c != cl - 1) {
            for (int i = rl - 2; i > r; i--)
                ans.push_back(matrix[i][c]);
        }

        justdo(matrix, r + 1, c + 1, rl - 1, cl - 1);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};

        int row = matrix.size();
        int col = matrix[0].size();

        justdo(matrix, 0, 0, row, col);

        return ans;
    }
};
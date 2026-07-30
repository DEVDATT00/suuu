class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int i, int j,
             int index, vector<vector<bool>>& visited) {

        if (index == word.size())
            return true;

        int row = board.size();
        int col = board[0].size();

        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;

        if (visited[i][j])
            return false;

        if (board[i][j] != word[index])
            return false;

        visited[i][j] = true;

        bool found =
            dfs(board, word, i + 1, j, index + 1, visited) ||
            dfs(board, word, i - 1, j, index + 1, visited) ||
            dfs(board, word, i, j + 1, index + 1, visited) ||
            dfs(board, word, i, j - 1, index + 1, visited);

        visited[i][j] = false;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
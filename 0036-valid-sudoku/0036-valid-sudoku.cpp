class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for (int i = 0; i < 9; i++) {
            s.clear();
            for (int j = 0; j < 9; j++) {
                char tem = board[i][j];
                if (tem == '.')
                    continue;
                if (s.find(tem) != s.end())
                    return false;
                s.insert(tem);
            }
        }
        for (int i = 0; i < 9; i++) {
            s.clear();
            for (int j = 0; j < 9; j++) {
                char tem = board[j][i];
                if (tem == '.')
                    continue;
                if (s.find(tem) != s.end())
                    return false;
                s.insert(tem);
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                s.clear();
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        char tem = board[i][j];
                        if (tem == '.')
                            continue;
                        if (s.find(tem) != s.end())
                            return false;
                        s.insert(tem);
                    }
                }
            }
        }
        return true;
    }
};
class Solution {
    int totalcount(vector<vector<int>>& temp, int i, int j, int m, int n) {
        int count = 0;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if (temp[ni][nj] == 1)
                    count++;
            }
        }

        return count;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> temp = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = totalcount(temp, i, j, m, n);

                if (temp[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                } else {
                    if (live == 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<int> q;

        for (auto &s : sources) {
            int r = s[0];
            int c = s[1];
            int color = s[2];

            if (grid[r][c] == 0) {
                grid[r][c] = color;
                q.push(r * m + c);
            } else {
                grid[r][c] = max(grid[r][c], color);
            }
        }

        vector<int> best(n * m, 0);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();
            vector<int> touched;

            while (size--) {
                int id = q.front();
                q.pop();

                int r = id / m;
                int c = id % m;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    int next = nr * m + nc;

                    if (grid[nr][nc] != 0)
                        continue;

                    if (best[next] == 0) {
                        best[next] = grid[r][c];
                        touched.push_back(next);
                    } else {
                        best[next] = max(best[next], grid[r][c]);
                    }
                }
            }

            for (int id : touched) {
                int r = id / m;
                int c = id % m;

                grid[r][c] = best[id];
                q.push(id);
                best[id] = 0;
            }
        }

        return grid;
    }
};
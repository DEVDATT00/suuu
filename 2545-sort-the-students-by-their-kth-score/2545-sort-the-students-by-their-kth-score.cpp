class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (score[j][k] < score[j + 1][k]) {
                    swap(score[j], score[j + 1]);
                }
            }
        }
        return score;
    }
};
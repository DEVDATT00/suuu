class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int reIndex = -1;
        int Mx = -1;
        for (int i = 0; i < towers.size(); i++) {
            int tem = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);
            if (tem <= radius) {
                if (Mx < towers[i][2]) {
                    Mx = towers[i][2];
                    reIndex = i;
                } else if (Mx == towers[i][2]) {
                    if (towers[i][0] < towers[reIndex][0] ||
                        (towers[i][0] == towers[reIndex][0] &&
                         towers[i][1] < towers[reIndex][1])) {
                        reIndex = i;
                    }
                }
            }
        }
        if (reIndex == -1)
            return {-1, -1};
        return {towers[reIndex][0], towers[reIndex][1]};
    }
};
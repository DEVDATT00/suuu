class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < drones.size(); i++) {
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (distance <= drones[i][2] && distance < minDistance) {
                minDistance = distance;
                ans = i;
            }
        }
        return ans;
    }
};
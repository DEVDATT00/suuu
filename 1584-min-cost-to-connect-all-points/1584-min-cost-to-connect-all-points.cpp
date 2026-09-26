class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        vector<int> dis(size, INT_MAX);
        vector<bool> visited(size, false);
        dis[0] = 0;
        int sum = 0;
        for (int count = 0; count < size; count++) {
            int index = -1;
            for (int i = 0; i < size; i++) {
                if (!visited[i] && (index == -1 || dis[i] < dis[index])) {
                    index = i;
                }
            }
            visited[index] = true;
            sum += dis[index];
            for (int i = 0; i < size; i++) {
                if (index == i)
                    continue;
                int distance = abs(points[index][0] - points[i][0]) +
                               abs(points[index][1] - points[i][1]);
                dis[i] = min(dis[i], distance);
            }
        }
        return sum;
    }
};
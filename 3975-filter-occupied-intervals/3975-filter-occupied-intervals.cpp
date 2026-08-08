class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> ans;

        for (auto &interval : occupiedIntervals) {
            if (ans.empty() || ans.back()[1] + 1 < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        vector<vector<int>> finalans;

        for (auto &interval : ans) {
            int start = interval[0];
            int end = interval[1];

            if (end < freeStart) {
                finalans.push_back(interval);
            }
            else if (start > freeEnd) {
                finalans.push_back(interval);
            }
            else if (start < freeStart && end <= freeEnd) {
                finalans.push_back({start, freeStart - 1});
            }
            else if (start >= freeStart && end > freeEnd) {
                finalans.push_back({freeEnd + 1, end});
            }
            else if (start < freeStart && end > freeEnd) {
                finalans.push_back({start, freeStart - 1});
                finalans.push_back({freeEnd + 1, end});
            }
        }

        return finalans;
    }
};
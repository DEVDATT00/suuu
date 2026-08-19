class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> seats;
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (seats.find(row) == seats.end()) {
                seats[row] = vector<bool>(10, true);
            }
            seats[row][col - 1] = false;
        }
        int count = (n - seats.size()) * 2;
        for (auto& [row, nums] : seats) {
            bool left = nums[1] && nums[2] && nums[3] && nums[4];
            bool middle = nums[3] && nums[4] && nums[5] && nums[6];
            bool right = nums[5] && nums[6] && nums[7] && nums[8];
            if (left && right)
                count += 2;
            else if (left || middle || right)
                count += 1;
        }
        return count;
    }
};
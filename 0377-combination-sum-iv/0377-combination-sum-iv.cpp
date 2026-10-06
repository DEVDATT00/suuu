class Solution {
    int solve(vector<int>& nums, int target, int currsum, vector<int>& dp) {
        if (currsum == target)
            return 1;
        if (dp[currsum] != -1)
            return dp[currsum];
        int count = 0;
        for (int i : nums) {
            if (currsum + i <= target) {
                count += solve(nums, target, currsum + i, dp);
            }
        }
        return dp[currsum] = count;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, 0, dp);
    }
};
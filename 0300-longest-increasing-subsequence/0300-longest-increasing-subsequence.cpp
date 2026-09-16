class Solution {
    int justdoit(vector<int>& nums, int index, int previous, vector<vector<int>>& dp) {
        if (index == nums.size())
            return 0;
        if (dp[index][previous + 1] != -1)
            return dp[index][previous + 1];
        int skip = justdoit(nums, index + 1, previous, dp);
        int take = 0;
        if (previous == -1 || nums[previous] < nums[index]) {
            take = 1 + justdoit(nums, index + 1, index, dp);
        }
        return dp[index][previous + 1] = max(take, skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return justdoit(nums, 0, -1, dp);
    }
};
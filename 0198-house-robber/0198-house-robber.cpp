class Solution {
    int let(vector<int>&nums , int index , vector<int>&dp){
        if(index >= nums.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int rob = nums[index] + let(nums, index + 2, dp);
        int skip = let(nums, index + 1, dp);

        return dp[index] = max(rob,skip);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return let(nums,0,dp);
    }
};
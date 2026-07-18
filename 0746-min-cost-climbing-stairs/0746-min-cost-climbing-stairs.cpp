class Solution {
    int solve(vector<int>& cost, int n, vector<int> &dp) {
        if (n >= cost.size()) {
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost, n + 1, dp), solve(cost, n + 2, dp));
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int total = 0;
        return min(solve(cost, 0, dp), solve(cost, 1,dp));
    }
};
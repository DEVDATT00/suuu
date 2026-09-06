class Solution {
    int doit(string &original, string &target, int index, int targetIndex, vector<vector<int>>& dp) {
        if (targetIndex == target.length()) {
            return 1;
        }
        if (index == original.length()) {
            return 0;
        }
        if (dp[index][targetIndex] != -1) {
            return dp[index][targetIndex];
        }
        int ans = 0;
        if (original[index] == target[targetIndex]) {
            ans += doit(original, target, index + 1, targetIndex + 1, dp);
        }
        ans += doit(original, target, index + 1, targetIndex, dp);
        return dp[index][targetIndex] = ans;
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return doit(s, t, 0, 0, dp);
    }
};
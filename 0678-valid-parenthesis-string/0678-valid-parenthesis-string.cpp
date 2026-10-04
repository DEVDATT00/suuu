class Solution {
    bool solve(string& s, vector<vector<int>>& dp, int index, int balance, int size) {
        if (balance < 0)
            return false;
        if (index == size)
            return balance == 0;
        if (dp[index][balance] != -1)
            return dp[index][balance];
        bool ans = false;
        if (s[index] == '(')
            ans = solve(s, dp, index + 1, balance + 1,size);
        else if (s[index] == ')')
            ans = solve(s, dp, index + 1, balance - 1,size);
        else
            ans = solve(s, dp, index + 1, balance + 1,size) || solve(s, dp, index + 1, balance - 1,size) || solve(s, dp, index + 1, balance , size);
        return dp[index][balance] = ans;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(s, dp, 0, 0,s.size());
    }
};
class Solution {
    bool a(string& s, vector<vector<int>>& dp, int i, int balance, int size) {
        if (i == size)
            return balance == 0;
        if (balance < 0)
            return false;
        if (dp[i][balance] != -1)
            return dp[i][balance];
        bool d = false;
        if (s[i] == '(')
            d = a(s, dp, i + 1, balance + 1, size);
        else if (s[i] == ')') {
            if (balance > 0)
                d = a(s, dp, i + 1, balance - 1, size);
        } else if (s[i] == '*') {
            d = a(s, dp, i + 1, balance + 1, size) || (balance > 0 && a(s, dp, i + 1, balance - 1, size)) || a(s, dp, i + 1, balance, size);
        }
        return dp[i][balance] = d;
    }

public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length() + 1, -1));
        return a(s, dp, 0, 0, s.length());
    }
};
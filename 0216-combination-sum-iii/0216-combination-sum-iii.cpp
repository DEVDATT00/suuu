class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& temp, int start, int k , int n, int sum) {
        if (temp.size() == k) {
            if (sum == n) {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (sum + i > n)
                break;
            temp.push_back(i);
            solve(ans, temp, i + 1, k, n, sum + i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 1, k, n, 0);
        return ans;
    }
};
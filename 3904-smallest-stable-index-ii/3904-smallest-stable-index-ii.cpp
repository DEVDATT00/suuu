class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i - 1], nums[i]);
        }
        int mn = INT_MAX;
        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            if (mx[i] - mn <= k) {
                ans = i;
            }
        }
        return ans;
    }
};
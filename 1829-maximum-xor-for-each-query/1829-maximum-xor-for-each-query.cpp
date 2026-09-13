class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int xr = 0;
        for (int num : nums) {
            xr ^= num;
        }
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < n; i++) {
            ans[i] = xr ^ mask;
            xr ^= nums[n - 1 - i];
        }
        return ans;
    }
};
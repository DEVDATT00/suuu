class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int size = 2 * k + 1;
        if (size > n) {
            return ans;
        }
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        ans[k] = sum / size;
        for (int i = k + 1; i < n - k; i++) {
            sum += nums[i + k];
            sum -= nums[i - k - 1];
            ans[i] = sum / size;
        }
        return ans;
    }
};
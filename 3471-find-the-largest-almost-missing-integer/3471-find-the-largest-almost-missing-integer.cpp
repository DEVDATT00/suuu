class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
        int n = nums.size();
        for(int x : nums) {
            freq[x]++;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
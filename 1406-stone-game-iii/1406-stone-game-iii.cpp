class Solution {
    vector<int> aliceDp;
    vector<int> bobDp;
    
    int alice(vector<int>& nums, int index) {
        if (index >= nums.size())
            return 0;

        if (aliceDp[index] != INT_MIN)
            return aliceDp[index];

        int ans = INT_MIN;
        int take = 0;

        for (int k = 0; k < 3 && index + k < nums.size(); k++) {
            take += nums[index + k];
            ans = max(ans, take + bob(nums, index + k + 1));
        }

        return aliceDp[index] = ans;
    }

    int bob(vector<int>& nums, int index) {
        if (index >= nums.size())
            return 0;

        if (bobDp[index] != INT_MIN)
            return bobDp[index];

        int ans = INT_MAX;
        int take = 0;

        for (int k = 0; k < 3 && index + k < nums.size(); k++) {
            take += nums[index + k];
            ans = min(ans, -take + alice(nums, index + k + 1));
        }

        return bobDp[index] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        aliceDp.assign(n, INT_MIN);
        bobDp.assign(n, INT_MIN);

        int diff = alice(stoneValue, 0);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};
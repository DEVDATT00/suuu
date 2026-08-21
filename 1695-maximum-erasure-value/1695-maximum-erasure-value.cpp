class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mxnumber = 0;
        for (int x : nums)
            mxnumber = max(mxnumber, x);
        vector<int> count(mxnumber + 1, 0);
        int i = 0;
        int mxsum = 0;
        int tempsum = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            while (count[nums[j]] > 0) {
                tempsum -= nums[i];
                count[nums[i]]--;
                i++;
            }
            tempsum += nums[j];
            count[nums[j]]++;
            mxsum = max(mxsum, tempsum);
        }
        return mxsum;
    }
};
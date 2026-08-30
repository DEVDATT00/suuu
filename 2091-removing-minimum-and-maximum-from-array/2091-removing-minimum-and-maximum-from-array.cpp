class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        int mn = 0;
        int mx = 0;
        for(int i = 1; i < n; i++) {
            if(nums[mn] > nums[i])
                mn = i;
            if(nums[mx] < nums[i])
                mx = i;
        }
        if(mn > mx)
            swap(mn, mx);
        int left = mx + 1;
        int right = n - mn;
        int both = (mn + 1) + (n - mx);
        return min({left, right, both});
    }
};
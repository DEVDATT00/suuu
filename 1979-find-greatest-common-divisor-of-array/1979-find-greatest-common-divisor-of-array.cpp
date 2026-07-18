class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        return gcd(mn, mx);
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x = nums.size() - 1;
        return (nums[x]-1)*(nums[x-1]-1);
    }
};
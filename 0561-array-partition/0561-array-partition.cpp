class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int count = 0;
        int n = nums.size() - 1;
        sort(nums.begin(),nums.end());
        for(int i = n ; i > 0 ; i -= 2){
            count += min(nums[i] , nums[i-1]);
        }
        return count;
    }
};
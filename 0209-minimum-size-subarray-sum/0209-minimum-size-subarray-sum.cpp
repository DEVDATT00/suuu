class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int i = 0 , n = nums.size();
        int size = INT_MAX;
        for(int j = 0; j < n ; j++){
            sum += nums[j];
            while(sum >= target){
                size = min(size,j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        if(size == INT_MAX)
            return 0;
        return size;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0 ;
        while(i < nums.size() && nums[i] < 0 ){
            nums[i] = abs(nums[i]);
            i++;
        }
        sort(nums.begin(),nums.end());
        for(i = 0 ; i < nums.size() ; i++){
            nums[i] = nums[i]*nums[i];
        }
        return nums;
    }
};
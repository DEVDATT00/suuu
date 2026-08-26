class Solution {
    int count = 0;
    int maxof = 0;
    void devdattpatel(vector<int>&nums,int i,int curr){
        if(nums.size() == i){
            if(curr == maxof)
                count++;
                return;
        }
        devdattpatel(nums,i+1,curr);
        devdattpatel(nums,i+1,curr | nums[i]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for(int i : nums)
            maxof |= i;
        devdattpatel(nums,0,0);
        return count;
    }
};
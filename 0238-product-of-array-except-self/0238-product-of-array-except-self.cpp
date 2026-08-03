class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total = 1;
        int countzero = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                countzero++;
                continue;
            }else{
                total *= nums[i];
            }
        }
        if(countzero > 1){
            fill(nums.begin(), nums.end(), 0);
            return nums;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(countzero == 1 && nums[i] != 0)
                nums[i] = 0;
            else if(nums[i] == 0)
                nums[i] = total;
            else if(nums[i] != 0)
                nums[i] = total / nums[i];
        }
        return nums;
    }
};
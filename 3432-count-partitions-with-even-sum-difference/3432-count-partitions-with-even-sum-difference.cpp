class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0 ;
        int total = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            total += nums[i];
        }
        int tem = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            tem += nums[i];
            total -= nums[i];
            if((tem - total)%2 == 0){
                count++;
            }
        }
        return count;
    }
};
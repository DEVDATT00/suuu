class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closer = INT_MAX;
        int sum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            int start = i + 1 , end = nums.size() - 1;
            while(start < end){
                int tem = nums[i]+nums[start]+nums[end];
                if(abs(target - tem) < closer){
                    closer = abs(target-tem);
                    sum = tem;
                }
                if(tem < target){
                    start++;
                }
                else if(tem > target){
                    end--;
                }
                else{
                    return target;
                }
            }
        }
        return sum;
    }
};
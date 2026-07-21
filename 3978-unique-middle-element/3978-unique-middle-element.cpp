class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size() / 2;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i == mid){
                continue;
            }
            if(nums[mid] == nums[i]){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        int e = nums.size() * (nums.size() + 1) / 2;
        int a = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            a += nums[i];
        }
        return e - a;
    }
};

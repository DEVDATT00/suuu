class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }
        int x = sum;
        while(true) {
            bool found = false;
            for(int i = 0; i < n; i++) {
                if(nums[i] == x) {
                    found = true;
                    break;
                }
            }
            if(!found)
                return x;
            x++;
        }
        return 1;
    }
};
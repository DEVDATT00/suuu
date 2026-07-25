class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0 , j = nums.size() - 1;
        double check = DBL_MAX;
        while(i <= j){
            check = min(check,(nums[i]+nums[j])/2.0);
            i++;
            j--;
        }
        return check;
    }
};
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int>f(mx + 1 , 0);
        for(int i : nums){
            f[i]++;
        }
        int i = 0 , j = 0 , n = nums.size() , counts = 0;
        while(i < n){
            while(j < n && nums[i] == nums[j])
                j++;
            if(f[nums[i]] == j - i)
                counts++;
            i = j;
        }
        return counts;
    }
};
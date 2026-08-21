class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0 , mx = 0 , zero = 0 , n = nums.size();
        for(int j = 0 ; j < n ; j++){
            if(!nums[j])
                zero++;
            while(zero > 1){
                if(!nums[i])
                    zero--;
                i++;
            }
            mx = max(mx , j - i);
        }
        return mx;
    }
};
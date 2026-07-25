class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int p = 0 , n = 1;
        for(int i : nums){
            if(i > 0){
                ans[p] = i;
                p += 2;
            }else if(i < 0){
                ans[n] = i;
                n += 2;
            }
        }
        return ans;
    }
};
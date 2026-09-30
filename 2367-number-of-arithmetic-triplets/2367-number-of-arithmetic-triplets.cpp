class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int num:nums){
            if(st.count(num+diff)&&st.count(num+2*diff)){
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = 0;
        for(int i : nums){
            mn = min(mn , i);
            mx = max(mx , i);
        }
        vector<bool>check(mx - mn - 1,true);
        for(int i : nums){
            if(i > mn && i < mx){
                check[i - mn - 1] = false;
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < check.size() ; i++){
            if(check[i])
                ans.push_back(mn + i + 1);
        }
        return ans;
    }
};
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int r = 0;
        vector<int>check;
        string s;
        int maxi , mini ,final = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            s = to_string(nums[i]);
            maxi = 0 ;
            mini = INT_MAX;
            for(int j = 0 ; j < s.length() ; j++){
                maxi = max(maxi , s[j] - '0');
                mini = min(mini , s[j] - '0');
            }
            final = max(final , maxi-mini);
            check.push_back(maxi-mini);
        }
        for(int i = 0 ; i < check.size() ; i++){
            if(check[i] == final){
                r += nums[i];
            }
        }
        return r;
    }
};
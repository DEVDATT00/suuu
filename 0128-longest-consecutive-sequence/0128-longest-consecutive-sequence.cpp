class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x : s) {
            if(s.find(x - 1) == s.end()) {
                int len = 1;
                while(s.find(x + 1) != s.end()) {
                    x++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
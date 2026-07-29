class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>count(256,0);
        int mx = 0;
        int i = 0 , j = 0;
        while(i < s.length() && j < s.length()){
            count[s[j]]++;
            while(count[s[j]] > 1){
                count[s[i]]--;
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};
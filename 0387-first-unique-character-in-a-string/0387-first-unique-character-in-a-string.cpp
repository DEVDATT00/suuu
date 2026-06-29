class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>tem(26,0);
        for(int i = 0 ; i < s.length() ; i++){
            tem[s[i] - 'a']++;
        }
        for(int i = 0 ; i < s.length() ; i++){
            if(tem[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
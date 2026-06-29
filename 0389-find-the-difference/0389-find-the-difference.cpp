class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>tem(26,0);
        char c;
        for(int i = 0 ; i < s.length() ; i++){
            tem[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t.length() ; i++){
            if(tem[t[i] - 'a'] == 0){
                c = t[i];
                break;
            }
            tem[t[i] - 'a']--;
        }
        return c;
    }
};
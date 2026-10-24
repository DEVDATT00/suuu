class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
        }
        int freq = mp.begin()->second;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if((it->second) != freq){
                return false;
            }
        }
        return true;
    }
};
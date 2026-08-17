class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int>tem1;
        unordered_map<char,int>tem2;
        for(int i = 0 ; i < s.length() ; i++){
            tem1[s[i]]++;
            tem2[t[i]]++;
        }
        for(auto it = tem1.begin() ; it != tem1.end() ; it++){
            auto found = tem2.find(it->first);
            if(found == tem2.end()){
                return false;
            }
            if((found->second) != (it->second)){
                return false;
            }

        }
        return true;
    }
};
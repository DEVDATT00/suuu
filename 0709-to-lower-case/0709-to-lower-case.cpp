class Solution {
public:
    string toLowerCase(string s) {
        string dev;
        for(int i = 0 ; i < s.length() ; i++){
            if(64 < s[i] && s[i] < 91 ){
                s[i] = s[i] + 32;
                dev.push_back(s[i]);
            }else{
                dev.push_back(s[i]);
            }
        }
        return dev;
    }
};
class Solution {
public:
    long long removeZeros(long long n) {
        long long done = 0 ;
        string s = to_string(n);
        string dev;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != '0'){
                dev.push_back(s[i]);
            }
        }
        return stoll(dev);
    }
};
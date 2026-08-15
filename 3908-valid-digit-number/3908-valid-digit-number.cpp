class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        string check = to_string(x);
        if(s[0] == check[0]){
            return false;
        }
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == check[0]){
                return true;
            }
        }
        return false;
    }
};
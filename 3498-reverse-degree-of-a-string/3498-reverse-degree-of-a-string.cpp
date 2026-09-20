class Solution {
public:
    int reverseDegree(string s) {
        int count = 0;
        for(int i = 0 ; i < s.length() ; i++){
            count = count + ( ( 123 - s[i] ) * (i + 1));
        }
        return count ;
    }
};
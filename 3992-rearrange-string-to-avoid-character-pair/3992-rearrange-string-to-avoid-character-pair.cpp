class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int i = 0 , j = s.length() - 1;
        while( i < j){
            while( i < j && s[i] != x){
                i++;
            }
            while(i < j && s[j] != y){
                j--;
            }
            if(i < j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
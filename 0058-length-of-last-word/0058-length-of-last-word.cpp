class Solution {
public:
    int lengthOfLastWord(string s) {
        int first = -1;
        int last = s.length();
        for(int i = 0 ; i < s.length()-1 ; i++){
            if(s[i] == ' ' && s[i+1] != ' '){
                first = i;
            }
        }
        for(int i = s.length() - 1; i >= 0 ; i--){
            if(s[i] != ' '){
                last = i;
                break;
            }
        }
        return abs(last-first );
    }
};
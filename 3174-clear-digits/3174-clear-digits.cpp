class Solution {
public:
    string clearDigits(string s) {
        string st;
        for(int i = 0 ; i < s.length() ; i++){
            if(isalpha(s[i])){
                st.push_back(s[i]);
            }else if(!isalpha(s[i])){
                if(!st.empty()){
                    st.pop_back();
                }
            }
        }
        return st;
    }
};
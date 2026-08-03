class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result = 0;
        int count = 0;
        int sign = 1;
        for(int i = 0 ; i < s.length() ; i++){
            if(isdigit(s[i])){
                long long  tem = 0;
                while(i < s.length() && isdigit(s[i])){
                    tem = tem * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * tem;
                i--;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }else if (s[i] == ')') {
                int prevSign = st.top();
                st.pop();

                int prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }
        return result;
    }
};
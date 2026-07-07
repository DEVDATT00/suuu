class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ;
        int n = s.length();
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i == n){
            return 0;
        }
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        long long number = 0;
        int digit ;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            digit = s[i] - '0';
            number = number * 10 + digit;
            if(sign * number < INT_MIN){
                return INT_MIN;
            }
            if(sign * number > INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return (int)(sign*number);
    }
};
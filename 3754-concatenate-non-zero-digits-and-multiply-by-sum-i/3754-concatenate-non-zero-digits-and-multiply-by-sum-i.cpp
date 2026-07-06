class Solution {
public:
    long long sumAndMultiply(int n) {
        int count = 0 ;
        int sum = 0;
        int tem;
        string s = to_string(n);
        for(int i = 0 ; i < s.length() ; i++){
            tem = s[i] - '0';
            if(tem){
                count = count * 10 + tem;
                sum += tem;
            }
        }
        return 1LL*count * sum;
    }
};
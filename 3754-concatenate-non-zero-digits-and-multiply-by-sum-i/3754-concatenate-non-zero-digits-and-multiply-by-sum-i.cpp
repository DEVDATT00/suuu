class Solution {
public:
    long long sumAndMultiply(int n) {
        long long count = 0 ;
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
        return count * sum;
        // long long x = 0;
        //     int r = 1;
        //     int sum_digits = 0;
        //     while (n > 0) {
        //         int d = n % 10;
        //         n /= 10;
        //         if (d == 0) continue;
        //         x = d * r + x;
        //         sum_digits += d;
        //         r *= 10;
        //     }
        //     return x * sum_digits;
    }
};
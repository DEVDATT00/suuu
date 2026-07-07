class Solution {
public:
    long long sumAndMultiply(int n) {
        long long c = 0 ;
        int s = 0;
        int t;
        string st = to_string(n);
        for(int i = 0 ; i < st.length() ; i++){
            t = st[i] - '0';
            if(t){
                c = c * 10 + t;
                s += t;
            }
        }
        return c * s;
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
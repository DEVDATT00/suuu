class Solution {
public:
    int mirrorDistance(int n) {
        long long rev ;
        int x = n;
        while(n > 0){
            int tem = n % 10 ;
            rev = rev * 10 + tem ;
            n = n / 10;
        }
        return abs(x - rev) ;
    }
};
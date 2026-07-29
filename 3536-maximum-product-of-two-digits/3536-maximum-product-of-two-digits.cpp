class Solution {
public:
    int maxProduct(int n) {
        int max = 0;
        int smax = 0;
        int tem ;
        while(n > 0){
            tem = n % 10;
            n = n / 10;
            if( tem > max){
                smax = max;
                max = tem;
                continue;
            }
            if(tem <= max && tem > smax){
                smax = tem;
            }
        }
        return max * smax;
    }
};
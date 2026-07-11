class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum = 0 ;
        long long product = 1;
        while(n > 0){
            int tem = n % 10 ;
            sum = sum + tem;
            product = product * tem;
            n = n / 10;
        }
        return product - sum;
    }
};
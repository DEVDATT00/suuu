class Solution {
public:
    int climbStairs(int n) {
        vector<int>d(n+1);
        if(n == 0){
            return 0;
        }if(n == 1){
            return 1;
        }
        d[0] = 1;
        d[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            d[i] = d[i-1]+d[i-2];
        }
        return d[n];
    }
};
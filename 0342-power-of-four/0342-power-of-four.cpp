class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0 || n > INT_MAX){
            return 0;
        }
        for(int i = 0 ; i < 20 ; i++){
            if(pow(4,i) == n){
                return 1;
            }
        }
        return 0;
    }
};
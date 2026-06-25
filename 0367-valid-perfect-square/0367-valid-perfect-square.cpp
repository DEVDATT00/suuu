class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1 ; i <= 46340 ; i++){
            if(pow(i,2) == num){
                return 1;
            }
        }
        return 0;
    }
};
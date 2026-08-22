class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int copyofN = n;
        while( copyofN > 0){
            sum += copyofN % 10;
            mul *= copyofN % 10;
            copyofN /= 10;
        }
        return n % (sum + mul) == 0;
    }
};
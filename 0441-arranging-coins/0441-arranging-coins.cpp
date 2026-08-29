class Solution {
public:
    int arrangeCoins(int n) {
        int countrows = 0;
        for (int i = 1 ; i <= n; i++ ) {
            n -= i;
            countrows++;
        }
        return countrows ;
    }
};
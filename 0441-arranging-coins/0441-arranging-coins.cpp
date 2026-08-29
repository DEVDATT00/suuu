class Solution {
public:
    int arrangeCoins(int n) {
        int countrows;
        int size = n;
        for (int i = 1 ; i <= n; i++ ) {
            n -= i;
            countrows++;
        }
        return countrows ;
    }
};
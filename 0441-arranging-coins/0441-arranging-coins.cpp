class Solution {
public:
    int arrangeCoins(int n) {
        int comp = 0;

        for (int i = 1; i<=n; i++) {
            n -= i;
            comp++;
        }

        return comp;
    }
};
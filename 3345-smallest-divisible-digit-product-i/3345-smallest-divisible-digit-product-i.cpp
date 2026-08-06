class Solution {
public:
    int smallestNumber(int n, int t) {
        if (t == 1)
            return n;
        int max = 10 - (n % 10);
        int tem;
        for (int i = 0; i < max; i++) {
            tem = n + i;
            int count = 1;

            while (tem > 0) {
                count *= tem % 10;
                tem /= 10;
            }

            if (count % t == 0)
                return n + i;
        }
        return n + max;
    }
};
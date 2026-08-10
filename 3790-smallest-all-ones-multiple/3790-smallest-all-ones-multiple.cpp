class Solution {
public:
    int minAllOneMultiple(int k) {
        int rem = 0;
        for (int count = 1; count <= k; count++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0)
                return count;
        }
        return -1;
    }
};
class Solution {
public:
    int minOperations(string s) {
        int maxDist = 0;
        for (char c : s) {
            int dist = ('a' - c + 26) % 26;
            maxDist = max(maxDist, dist);
        }
        return maxDist;
    }
};
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int dx = abs(coordinate1[0] - coordinate2[0]);
        int dy = abs(coordinate1[1] - coordinate2[1]);

        return (dx % 2) == (dy % 2);
    }
};
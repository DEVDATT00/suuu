class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        for (int i : nums)
            mn = min(mn, i);
        int count = 0;
        for (int i : nums)
            count += i - mn;
        return count;
    }
};
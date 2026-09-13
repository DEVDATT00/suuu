class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int x : nums) {
            actualSum += x;
        }
        int repeated = 0;
        vector<int> freq(n + 1, 0);
        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) {
                repeated = x;
            }
        }
        int missing = expectedSum - actualSum + repeated;
        return {repeated, missing};
    }
};
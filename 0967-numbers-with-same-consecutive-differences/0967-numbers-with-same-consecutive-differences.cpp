class Solution {
    void makeit(std::vector<int>& ans, int n, int k, int num) {
        if (n == 0) {
            ans.push_back(num);
            return;
        }
        int lastDigit = num % 10;
        if (lastDigit + k <= 9) {
            makeit(ans, n - 1, k, num * 10 + (lastDigit + k));
        }
        if (k != 0 && lastDigit - k >= 0) {
            makeit(ans, n - 1, k, num * 10 + (lastDigit - k));
        }
    }
public:
    std::vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            makeit(ans, n - 1, k, i);
        }
        return ans;
    }
};
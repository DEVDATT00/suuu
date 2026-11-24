class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(), banned.end());
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (s.count(i))
                continue;

            if (i > maxSum)
                break;

            maxSum -= i;
            count++;
        }

        return count;
    }
};

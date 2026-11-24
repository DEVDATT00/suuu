class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        int sum = 0;

        set<int> s;
        for (int i : banned)
            s.insert(i);

        for (int i = 1; i <= n; i++) {
            if (s.find(i) != s.end())
                continue;

            if (sum + i > maxSum)
                break;

            sum += i;
            count++;
        }

        return count;
    }
};
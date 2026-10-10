class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2) {
        int n = nums1.size();
        long long operations = (long long)k1 + k2;
        vector<long long> diff(n);
        long long maxDiff = 0;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i] * diff[i];
        }
        if (operations >= accumulate(diff.begin(), diff.end(), 0LL))
            return 0;
        long long left = 0, right = maxDiff;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long required = 0;
            for (long long d : diff) {
                if (d > mid)
                    required += d - mid;
            }
            if (required <= operations)
                right = mid;
            else
                left = mid + 1;
        }
        long long level = left;
        long long remaining = operations;
        for (long long d : diff) {
            if (d > level) {
                remaining -= d - level;
                d = level;
            }
        }
        long long answer = 0;
        for (long long d : diff) {
            long long reduced = min(d, level);
            answer += reduced * reduced;
        }
        answer -= remaining * (2 * level - 1);
        return answer;
    }
};
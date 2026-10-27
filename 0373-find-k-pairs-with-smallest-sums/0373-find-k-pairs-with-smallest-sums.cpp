class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0 || m == 0 || k == 0)
            return ans;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < min(n, k); i++)
            pq.push({nums1[i] + nums2[0], i, 0});
        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return ans;
    }
};
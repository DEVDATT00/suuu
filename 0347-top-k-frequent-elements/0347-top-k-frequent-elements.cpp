class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;
        priority_queue<pair<int, int>> q;
        for (auto it = m.begin(); it != m.end(); it++)
            q.push({it->second, it->first});
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
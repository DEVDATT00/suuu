class Solution {
    set<vector<int>> m;
    void devdatt(vector<int>& nums, vector<int> output, int i) {
        if (i == nums.size()) {
            m.insert(output);
            return;
        }
        devdatt(nums, output, i + 1);
        output.push_back(nums[i]);
        devdatt(nums, output, i + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        devdatt(nums, output, 0);
        for (auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};
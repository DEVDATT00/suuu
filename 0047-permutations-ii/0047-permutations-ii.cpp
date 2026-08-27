class Solution {
    void doit(vector<int>& nums, vector<vector<int>>& ans, int index) {
        int n = nums.size();
        if(index == n) {
            ans.push_back(nums);
            return;
        }
        set<int> used;
        for(int j = index; j < n; j++) {
            if(used.count(nums[j]))
                continue;
            used.insert(nums[j]);
            swap(nums[index], nums[j]);
            doit(nums, ans, index + 1);
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        doit(nums, ans, 0);
        return ans;
    }
};
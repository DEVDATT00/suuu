class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> tem = nums;
        sort(tem.begin(), tem.end());
        int n = tem.size();
        vector<int> ans;
        for (int num : nums) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (tem[mid] >= num) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans.push_back(left);
        }
        return ans;
    }
};
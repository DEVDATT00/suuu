class Solution {
    bool findout(vector<int>& nums, int index, int size) {
        if (index < 0 || index >= size)
            return false;
        if (nums[index] == -1)
            return false;
        if (nums[index] == 0)
            return true;
        int jump = nums[index];
        nums[index] = -1;
        return findout(nums, index + jump, size) || findout(nums, index - jump, size);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        return findout(arr, start, arr.size());
    }
};
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            hash[nums[i]] = i;
            for (int j = i; j >= 0; j--) {
                sum = sum + nums[j];
                if (hash.find(sum) != hash.end() &&
                    (j <= hash[sum] && hash[sum] <= i))
                    count++;
            }
        }
        return count;
    }
};
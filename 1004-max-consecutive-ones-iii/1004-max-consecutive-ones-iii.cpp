class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int countzeros = 0;
        int retur = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] == 0)
                countzeros++;
            while(countzeros > k) {
                if(nums[i] == 0)
                    countzeros--;
                i++;
            }
            retur = max(retur, j - i + 1);
        }
        return retur;
    }
};
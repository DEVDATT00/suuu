class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx = 0;
        for(int i : nums){
            sum += i;
            mx = max(mx , i);
        }
        return (mx* n) - sum;
    }
};
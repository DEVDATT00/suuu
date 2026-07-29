class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>count(101,0);
        for(int i : nums){
            count[i]++;
        }
        int ans = 0;
        for(int i : count){
            ans += i * ( i - 1 ) / 2;
        }
        return ans;
    }
};
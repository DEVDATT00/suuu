class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int tem = (100 / k) + 2;
        vector<int> check(tem, true);
        for(int i : nums) {
            if(i % k == 0)
                check[i / k] = false;
        }
        for(int i = 1; i < tem; i++) {
            if(check[i])
                return i * k;
        }
        return 0;
    }
};
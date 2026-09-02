class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for(int i = 0;i < nums.size();i++){
            int curr = abs(nums[i]);
            if(curr == 0 && digit == 0){
                cnt++;
                continue;
            }
            while(curr != 0){
                if(curr % 10 == digit){
                    cnt++;
                }
                curr /= 10;
            }
        }
        return cnt;
    }
};
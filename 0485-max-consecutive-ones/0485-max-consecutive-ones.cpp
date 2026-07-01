class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0 ;
        int i = 0 , j ;
        while(i < nums.size()){
            while( i < nums.size() && nums[i] != 1){
                i++;
            }
            j = i;
            while(j < nums.size() && nums[j] != 0){
                j++;
            }
            maxi = max(maxi, j-i);
            i = j ;
        }
        return maxi;
    }
};
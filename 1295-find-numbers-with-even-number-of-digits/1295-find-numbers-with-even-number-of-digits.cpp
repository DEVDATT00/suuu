class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count , even=0;
        for(int i = 0 ; i < nums.size() ; i++ ){
           count = 0;
           int x = nums[i];
            while(x){
               x = x / 10;
              count++ ;
            }
            if(count % 2 == 0)
                even++;
        }
        return even;
    }
};
class Solution {
    void devdatt(vector<int>& nums , vector<vector<int>>&ans, int index){
        int size = nums.size();
        if(index == size){
            ans.push_back(nums);
            return;
        }
        for(int j = index ; j < size ; j++){
            swap(nums[index],nums[j]);
            devdatt(nums,ans,index+1);
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        devdatt(nums,ans,0);
        return ans;
    }
};
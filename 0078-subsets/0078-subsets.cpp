class Solution {
    void devdatt(vector<int>&nums,vector<vector<int>>&ans,vector<int>output,int index){
        if(index == nums.size()){
            ans.push_back(output);
            return;
        }
        devdatt(nums,ans,output,index+1);
        output.push_back(nums[index]);
        devdatt(nums,ans,output,index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        devdatt(nums,ans,output,index);
        return ans;
    }
};
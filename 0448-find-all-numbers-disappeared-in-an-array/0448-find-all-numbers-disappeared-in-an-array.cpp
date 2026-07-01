class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int maxi = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        vector<int> ans;
        if(maxi > nums.size()){
            ans.resize(maxi+1, 0);
        }else{
            ans.resize(nums.size()+1, 0);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            ans[nums[i]]++;
        }vector<int>final;
        for(int i = 1 ; i < ans.size() ; i++){
            if(!ans[i]){
                final.push_back(i);
            }
        }
        return final;
    }
};
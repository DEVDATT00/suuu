class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i = 0 ; i < nums.size() ; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin() , v.end());
        int i = 0 , j = v.size() - 1;
        vector<int>ans;
        while(i < j){
            if(v[i].first + v[j].first == target){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                break;
            }else if(v[i].first + v[j].first > target){
                j--;
            }else if(v[i].first + v[j].first < target){
                i++;
            }
        }
        return ans;
    }
};
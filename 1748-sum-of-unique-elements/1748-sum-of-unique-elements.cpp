class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int count = 0 ; 
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(auto dev = mp.begin() ; dev != mp.end() ; dev++){
            if((dev->second) == 1){
                count += (dev->first);
            }
        }
        return count;
    }
};
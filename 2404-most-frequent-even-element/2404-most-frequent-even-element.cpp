class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0 ){
                mp[nums[i]]++;
            }
        }
        int num = -1;
        int freq = 0;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if((it->second) == freq){
                num = min(num,(it->first));
            }
            if((it->second) > freq){
                freq = it->second;
                num = it->first;
            }
        }
        return num;
    }
};
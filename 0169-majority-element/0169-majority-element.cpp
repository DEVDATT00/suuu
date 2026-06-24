class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = (nums.size()) / 2;
        int tem ;
        unordered_map<int,int>map;
        for(int i = 0 ; i < nums.size() ; i++ ){
            map[nums[i]]++;
        }
        for(auto it = map.begin() ; it != map.end() ; it++){
            if(count < it->second){
                tem = it->first;
            }
        }
        return tem;
    }
};
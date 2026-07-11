class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            for(auto dev = mp.begin() ; dev != mp.end() ; dev++){
                if(dev == it){
                    continue;
                }
                if((it->second) == (dev->second)){
                    return false;
                }
            }
        }
        return true;
    }
};
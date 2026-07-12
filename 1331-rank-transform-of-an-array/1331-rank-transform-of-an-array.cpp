class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>tem;
        tem = arr;
        sort(tem.begin(),tem.end());
        map<int,int>mp;
        int t = 1;
        for(int i = 0 ; i < tem.size() ; i++){
            if(mp.find(tem[i]) == mp.end()){
                mp[tem[i]] = t;
                t++;
            }
        }
        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int small = INT_MAX;
        int notvisitthis = -1;
        int mx = INT_MIN;
        for(int i = 0 ; i < arrays.size() ; i++){
            if(small > arrays[i][0]){
                small = arrays[i][0];
                notvisitthis = i;
            }
        }
        for(int i = 0 ; i < arrays.size() ; i++){
            if( i == notvisitthis)
                continue;
            mx = max(mx , arrays[i].back());
        }
        small = abs(mx - small);
        mx = arrays[notvisitthis].back();
        for(int i = 0 ; i < arrays.size() ; i++){
            if(i == notvisitthis){
                continue;
            }
            small = max(small , abs(mx-arrays[i][0]));
        }
        return small;
    }
};
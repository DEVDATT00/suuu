class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = intervals.size();
        vector<bool>check(intervals.size(),true);
        for(int i = 0 ; i < intervals.size() ; i++){
            if(!check[i]){
                continue;
            }
            for(int j = 0 ; j < intervals.size() ; j++){
                if(!check[j] || i == j){
                    continue;
                }
                if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] ){
                    count--;
                    check[j] = false;
                }
            }
        }
        return count;
    }
};
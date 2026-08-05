class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        stack<vector<int>>just;
        just.push(points[0]);
        for(int i = 1 ; i < points.size() ; i++){
            if(points[i][0] <= just.top()[1]){
                just.top()[1] = min(just.top()[1] , points[i][1]);
            }else{
                just.push(points[i]);
            }
        }
        int count = 0;
        while(!just.empty()){
            just.pop();
            count++;
        }
        return count;
    }
};
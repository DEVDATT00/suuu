class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int x = 0;
        vector<int> b;
        for(int j = 0 ; j < heights.size() ; j++){
            b.push_back(heights[j]);
        }
        sort(b.begin(),b.end());
        for(int i = 0; i < heights.size();i++){
            if(heights[i] != b[i]){
                x++;
            }
        }
        return x;
    }
};
class Solution {
    void creation(vector<vector<int>>&ans,int numRows , int i ){
        if(numRows == i){
            return;
        }
        vector<int>tem;
        tem.push_back(1);
        for(int j = 0 ; j < ans[i-1].size()-1 ; j++){
            tem.push_back(ans[i-1][j]+ans[i-1][j+1]);
        }
        tem.push_back(1);
        ans.push_back(tem);
        creation(ans,numRows,i+1);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if (numRows >= 1)
            ans.push_back({1});

        if (numRows >= 2)
            ans.push_back({1, 1});

        if (numRows < 3)
            return ans;
        creation(ans,numRows,2);
        return ans;
    }
};
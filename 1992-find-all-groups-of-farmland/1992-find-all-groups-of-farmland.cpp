class Solution {
    void findout(vector<vector<int>>& land,vector<int>&tem,int i , int j , int row , int col){
        if(i >= row || j >= col || land[i][j] == 0)
            return;
        tem[2] = max(tem[2],i);
        tem[3] = max(tem[3],j);
        land[i][j] = 0;
        findout(land,tem,i+1,j,row,col);
        findout(land,tem,i,j+1,row,col);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int row = land.size();
        int col = land[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(land[i][j]){
                    vector<int>tem(4,0);
                    tem[0] = i;
                    tem[1] = j;
                    findout(land,tem,i,j,row,col);
                    ans.push_back(tem);
                }
            }
        }
        return ans;
    }
};
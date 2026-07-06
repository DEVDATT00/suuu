class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> a;
        int count = 0 ;
        int max = 0 ;
        for(int i = 0 ; i < accounts.size() ; i++){
            for(int j = 0 ; j < accounts[i].size() ; j++){
                count = count + accounts[i][j];
            }
            if(count > max){
                max = count;
            }
            a.push_back(count);
            count = 0;
        }
        return max;
    }
};
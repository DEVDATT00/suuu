class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxi = 0 ;
        for(int i = 0 ; i < edges.size() ; i++){
            maxi = max(maxi,edges[i][1]);
            maxi = max(maxi,edges[i][0]);
        }
        vector<int>t(maxi+1);
        for(int i = 0 ; i < edges.size() ; i++){
            t[edges[i][0]]++;
            t[edges[i][1]]++;
        }
        maxi = edges.size() ;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i] == maxi){
                return i;
            }
        }
        return -1;
    }
};
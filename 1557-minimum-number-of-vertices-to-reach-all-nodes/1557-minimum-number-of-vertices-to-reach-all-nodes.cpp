class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>in(n,true);
        for(int i = 0 ; i < edges.size() ; i++){
            in[edges[i][1]] = false;
        }
        vector<int>ans;
        for(int i = 0 ; i < in.size() ; i++){
            if(in[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
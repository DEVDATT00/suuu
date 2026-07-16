class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> tem(edges.size(), 0);
        int n = edges.size();

        for (int i = 0; i < n ; i++) {
            tem[edges[i]] += i;
        }

        int res=0;
        for (int i = 1; i < n; i++){
            if (tem[i]>tem[res]) res=i;
        }
        return res;
    }
};
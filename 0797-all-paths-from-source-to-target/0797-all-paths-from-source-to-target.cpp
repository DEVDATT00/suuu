class Solution {
    void t(vector<vector<int>>& ans, vector<int>& tem,vector<vector<int>>& graph, int target, int start) {
        tem.push_back(start);
        if (start == target) {
            ans.push_back(tem);
        }
        for (int i = 0; i < graph[start].size(); i++) {
            t(ans, tem, graph, target, graph[start][i]);
        }
        tem.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tem;
        vector<vector<int>> ans;
        t(ans, tem, graph, graph.size() - 1, 0);
        return ans;
    }
};
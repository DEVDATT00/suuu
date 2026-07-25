class Solution {
public:
    vector<int> ans;
    bool check(vector<vector<int>>& graph, int i, vector<int>& state) {
        if (state[i] == 1)
            return false;
        if (state[i] == 2)
            return true;
        state[i] = 1;
        for (int j = 0; j < graph[i].size(); j++) {
            if (!check(graph, graph[i][j], state))
                return false;
        }
        state[i] = 2;
        ans.push_back(i);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        for (int i = 0; i < n; i++) {
            check(graph, i, state);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
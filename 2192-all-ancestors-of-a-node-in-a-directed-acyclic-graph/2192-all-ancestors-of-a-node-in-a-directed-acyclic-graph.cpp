class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,vector<int>& temp) {
        for (auto parent : adj[node]) {
            if (!visited[parent]) {
                visited[parent] = 1;
                temp.push_back(parent);
                dfs(parent, adj, visited, temp);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            vector<int> temp;
            dfs(i, adj, visited, temp);
            sort(temp.begin(), temp.end());
            ans[i] = temp;
        }
        return ans;
    }
};
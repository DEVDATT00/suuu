class Solution {
public:
    void dfs(int index, int& node, int& edge, vector<bool>& visit,vector<vector<int>>& adj) {
        if (!visit[index])
            return;
        visit[index] = false;
        node++;
        for (int tem : adj[index]) {
            edge++;
            if (visit[tem]) {
                dfs(tem, node, edge, visit, adj);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<bool> visit(n, true);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i])
                continue;
            int nodes = 0;
            int edge = 0;
            dfs(i, nodes, edge, visit, adj);
            edge /= 2;
            if (edge == nodes * (nodes - 1) / 2)
                count++;
        }
        return count;
    }
};
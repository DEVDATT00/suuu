class Solution {
public:
    vector<vector<int>> adj;
    vector<int> count;
    vector<int> ans;
    void dfs1(int node, int parent, int depth) {
        ans[0] += depth;
        count[node] = 1;
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }
            dfs1(child, node, depth + 1);
            count[node] += count[child];
        }
    }
    void dfs2(int node, int parent, int n) {
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }
            ans[child] = ans[node] + n - 2 * count[child];
            dfs2(child, node, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        count.resize(n, 0);
        ans.resize(n, 0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1, n);
        return ans;
    }
};
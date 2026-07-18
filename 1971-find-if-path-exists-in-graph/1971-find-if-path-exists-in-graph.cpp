class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int i = 0; i < graph[node].size(); i++) {
                int neighbour = graph[node][i];

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};
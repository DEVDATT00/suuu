class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<vector<int>> map(n);
        vector<int> ones(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            ones[u]++;
            ones[v]++;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ones[i] == 1)
                q.push(i);
        }
        int remaining = n;
        while (remaining > 2) {
            int size = q.size();
            remaining -= size;
            while (size--) {
                int node = q.front();
                q.pop();
                for (int neighbour : map[node]) {
                    ones[neighbour]--;
                    if (ones[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
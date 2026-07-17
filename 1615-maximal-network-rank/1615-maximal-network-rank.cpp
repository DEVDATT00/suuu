class Solution {
    bool check(unordered_map<int, list<int>>& mp, int u, int v) {
        for (int x : mp[u]) {
            if (x == v) {
                return true;
            }
        }
        return false;
    }

public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if (n == 2) {
            return roads.size();
        }
        unordered_map<int, list<int>> mp;
        vector<int> count(n, 0);
        int u, v;
        for (int i = 0; i < roads.size(); i++) {
            u = roads[i][0];
            v = roads[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            count[u]++;
            count[v]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = count[i] + count[j];

                if (check(mp, i, j))
                    rank--;

                ans = max(ans, rank);
            }
        }
        return ans;
    }
};
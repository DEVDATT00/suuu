class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, list<int>> m;
        int n = quiet.size();
        vector<int> fre(n, 0);
        for (int i = 0; i < richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            fre[v]++;
            m[u].push_back(v);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (fre[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int tem = q.front();
            q.pop();
            for (auto v : m[tem]) {
                if (quiet[ans[tem]] < quiet[ans[v]]) {
                    ans[v] = ans[tem];
                }
                fre[v]--;
                if (fre[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
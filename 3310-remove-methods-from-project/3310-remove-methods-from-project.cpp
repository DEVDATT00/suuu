class Solution {
    void suspicious(unordered_map<int, list<int>>& adjancy,
                    int u,
                    vector<bool>& suspiciousMethod) {

        if (suspiciousMethod[u])
            return;

        suspiciousMethod[u] = true;

        for (int v : adjancy[u]) {
            suspicious(adjancy, v, suspiciousMethod);
        }
    }

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        unordered_map<int, list<int>> adjancy;

        for (auto &x : invocations) {
            adjancy[x[0]].push_back(x[1]);
        }

        vector<bool> suspiciousMethod(n, false);

        suspicious(adjancy, k, suspiciousMethod);

        // Check if any non-suspicious method invokes a suspicious one.
        for (auto &x : invocations) {
            int u = x[0];
            int v = x[1];

            if (!suspiciousMethod[u] && suspiciousMethod[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Otherwise return the remaining methods.
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspiciousMethod[i])
                ans.push_back(i);
        }

        return ans;
    }
};
class Solution {
    bool doit(int index, vector<int>& ans, vector<int>& visit,vector<int>& path, unordered_map<int, list<int>>& m) {
        visit[index] = 1;
        path[index] = 1;
        for (auto node : m[index]) {
            if (!visit[node]) {
                if (doit(node, ans, visit, path, m)) {
                    return true;
                }
            } else if (path[node]) {
                return true;
            }
        }
        ans.push_back(index);
        path[index] = 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> m;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            m[v].push_back(u);
        }
        vector<int> ans;
        vector<int> visit(numCourses, 0);
        vector<int> path(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if (doit(i, ans, visit, path, m)) {
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
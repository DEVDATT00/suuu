class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
                q.push(node->left);
            }
            if (node->right) {
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
                q.push(node->right);
            }
        }
        int count = 0;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while (!q.empty() && count < k) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                for (TreeNode* next : adj[node]) {
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            count++;
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
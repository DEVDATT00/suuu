/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> layersum;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long count = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                count += node->val;
                if (node->right != nullptr)
                    q.push(node->right);
                if (node->left != nullptr)
                    q.push(node->left);
            }
            layersum.push_back(count);
        }
        if (layersum.size() < k)
            return -1;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < k; i++)
            pq.push(layersum[i]);
        for (int i = k; i < layersum.size(); i++) {
            if (pq.top() < layersum[i]) {
                pq.pop();
                pq.push(layersum[i]);
            }
        }
        return pq.top();
    }
};
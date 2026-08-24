class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int even = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (even % 2 == 1) {
                int i = 0;
                int j = nodes.size() - 1;
                while (i < j) {
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }
            even++;
        }
        return root;
    }
};
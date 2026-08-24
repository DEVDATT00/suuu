class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        bool level = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int prev;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!level) {
                    if (node->val % 2 == 0)
                        return false;
                    if (i > 0 && node->val <= prev)
                        return false;
                }
                else {
                    if (node->val % 2 == 1)
                        return false;
                    if (i > 0 && node->val >= prev)
                        return false;
                }
                prev = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level = !level;
        }
        return true;
    }
};
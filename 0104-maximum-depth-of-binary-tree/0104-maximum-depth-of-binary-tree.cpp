/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mx(TreeNode* node , int count){
        if(node == nullptr){
            return count;
        }
        return max(mx(node->left,count + 1),mx(node->right,count + 1));
    }
public:
    int maxDepth(TreeNode* root) {
        int count = 0;
        count = mx(root , count);
        return count;
    }
};
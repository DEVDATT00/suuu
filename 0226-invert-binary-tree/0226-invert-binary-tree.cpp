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
    void doswap(TreeNode * node,TreeNode*&dummy){
        if(node == nullptr){
            return;
        }
        dummy = node -> left;
        node->left = node->right;
        node->right = dummy;
        doswap(node->left,dummy);
        doswap(node->right,dummy);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode * dummy = root;
        doswap(root,dummy);
        return root;
    }
};
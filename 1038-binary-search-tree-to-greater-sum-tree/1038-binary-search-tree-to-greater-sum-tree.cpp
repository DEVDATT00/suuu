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
    void justdo(TreeNode * node , int & count){
        if(node == nullptr){
            return ;
        }
        justdo(node->right,count);
        count += node->val;
        node -> val = count;
        justdo(node->left,count);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int count = 0;
        justdo(root,count);
        return root;
    }
};
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
    void make(TreeNode* t,TreeNode*& curr){
        if(t == nullptr){
            return;
        }
        make(t->left,curr);
        curr->right = new TreeNode(t->val);
        curr = curr->right;
        
        make(t->right,curr);

    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;
        make(root,curr);
        return dummy->right;
    }
};
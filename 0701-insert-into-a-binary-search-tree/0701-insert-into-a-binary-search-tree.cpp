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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        TreeNode * curr  = root;
        int tem;
        while(true){
            tem = root->val;
            if(tem <= val && root->right == nullptr){
                root->right = new TreeNode(val);
                break;
            }else if(tem > val && root->left == nullptr){
                root->left = new TreeNode(val);
                break;
            }else if(tem <= val){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return curr ;
    }
};
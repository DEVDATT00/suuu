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
    void insertat(TreeNode * root , int val){
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
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size() ; i++){
            insertat(root,preorder[i]);
        }
        return root;
    }
};
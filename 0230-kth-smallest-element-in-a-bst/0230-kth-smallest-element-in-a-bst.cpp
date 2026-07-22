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
    void check(TreeNode * node , int k , int& i,int &tem){
        if(node == nullptr){
            return ;
        }
        check(node->left,k,i,tem);
        i++;
        if(i == k){
            tem = node->val;
            return;
        }
        check(node->right,k,i,tem);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int tem ;
        int count = 0;
        check(root,k,count,tem);
        return tem;
    }
};
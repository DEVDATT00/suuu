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
    void dothat(TreeNode * node , int low , int high , int & count){
        if(node == nullptr){
            return;
        }
        int tem = node -> val;
        if(tem >= low && tem <= high){
            count += tem;
        }
        dothat(node->left,low,high,count);
        dothat(node->right,low,high,count);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count = 0;
        dothat(root,low,high,count);
        return count;
    }
};
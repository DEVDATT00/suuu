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
    void visitall(TreeNode* node , int& sum){
        if(node == nullptr)
            return;
        visitall(node -> right , sum);
        sum += node -> val;
        node -> val = sum;
        visitall(node -> left , sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        visitall(root,sum);
        return root;
    }
};
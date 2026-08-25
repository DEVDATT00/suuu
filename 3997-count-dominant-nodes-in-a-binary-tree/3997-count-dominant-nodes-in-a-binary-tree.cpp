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
    int count = 0;
    int findout(TreeNode* node){
        if(node == nullptr)
            return 0;
        int leftpart = findout(node -> left );
        int rightpart = findout(node -> right);
        int mx = max(node->val , max(rightpart,leftpart));
        if(mx == node -> val)
            count++;
        return mx;
    }
public:
    int countDominantNodes(TreeNode* root) {
        findout(root);
        return count;
    }
};
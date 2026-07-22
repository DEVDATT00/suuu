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
    bool check(TreeNode * first , TreeNode * second){
        if(first == nullptr && second == nullptr){
            return true;
        }
        if(first == nullptr || second == nullptr){
            return false;
        }
        if(first -> val != second -> val){
            return false;
        }
        return check(first->right,second->right)&&check(first->left,second->left);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
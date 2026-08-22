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
    int search(vector<int>&nums,int start , int end){
        int index = start;
        for(int i = start + 1 ; i <= end ; i++){
            if(nums[i] > nums[index])
                index = i;
        }
        return index;
    }
    TreeNode* build(vector<int>&nums,int start , int end){
        if(start > end)
            return nullptr;
        int index = search(nums,start,end);
        TreeNode* head = new TreeNode(nums[index]);
        head -> right = build(nums,index + 1, end);
        head ->left = build(nums,start , index -1);
        return head;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};
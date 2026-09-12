class Solution {
    void justmakeit(TreeNode* papa, TreeNode* grandpa, int& count) {
        if (papa == nullptr)
            return;
        if (grandpa != nullptr && grandpa->val % 2 == 0) {
            if (papa->left != nullptr)
                count += papa->left->val;
            if (papa->right != nullptr)
                count += papa->right->val;
        }
        justmakeit(papa->left, papa, count);
        justmakeit(papa->right, papa, count);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int count = 0;
        justmakeit(root, nullptr, count);
        return count;
    }
};
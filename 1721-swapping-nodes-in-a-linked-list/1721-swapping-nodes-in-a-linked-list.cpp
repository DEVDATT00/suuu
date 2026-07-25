/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0 ;
        ListNode* tem = head;
        while(tem != nullptr){
            n++;
            tem = tem -> next;
        }
        tem = head;
        ListNode* tem1 = head;
        for (int i = 1; i < k; i++){
            tem = tem->next;
        }
        for (int i = 1; i < n - k + 1; i++){
            tem1 = tem1->next;
        }
        swap(tem->val,tem1->val);
        return head;
    }
};
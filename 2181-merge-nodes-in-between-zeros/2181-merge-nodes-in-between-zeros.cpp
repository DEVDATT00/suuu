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
    ListNode* mergeNodes(ListNode* head) {
        int count = 0 ;
        ListNode* firstzero = head;
        ListNode* track = firstzero;
        ListNode* pre = NULL;
        ListNode* secondzero = firstzero -> next;
        while(secondzero != nullptr){
            while(secondzero != NULL && secondzero -> val != 0){
                count += secondzero -> val; 
                secondzero = secondzero -> next;
            }
            track -> val = count;
            pre = track;
            track = track -> next;
            count = 0;
            firstzero = secondzero;
            if (secondzero != nullptr){
                secondzero = secondzero->next;
            }
        }
        pre -> next = nullptr;
        return head;
    }
};
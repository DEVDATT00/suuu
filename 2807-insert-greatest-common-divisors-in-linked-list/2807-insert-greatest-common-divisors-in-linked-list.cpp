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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* current = head;
        ListNode* n = current -> next;
        while(n != NULL){
            ListNode* node = new ListNode(gcd(current -> val, n -> val));
            current -> next = node;
            node -> next = n;
            current = node -> next;
            n = n -> next;
        }
        return head;
    }
};
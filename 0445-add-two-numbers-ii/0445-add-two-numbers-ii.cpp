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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> first, second;
        while (l1 != nullptr) {
            first.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            second.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int carry = 0;
        while (!first.empty() || !second.empty() || carry) {
            int sum = carry;
            if (!first.empty()) {
                sum += first.top();
                first.pop();
            }
            if (!second.empty()) {
                sum += second.top();
                second.pop();
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};
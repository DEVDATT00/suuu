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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* node = head;
        int count = 1;

        while (count < left) {
            node = node->next;
            count++;
        }

        ListNode* start = node;

        stack<int> st;

        for (int i = left; i <= right; i++) {
            st.push(node->val);
            node = node->next;
        }

        node = start;

        while (!st.empty()) {
            node->val = st.top();
            st.pop();
            node = node->next;
        }

        return head;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)return head;
        int cnt = 0 ;
        ListNode* count = head;
        while(count != nullptr){
            cnt++;
            if(count -> next == nullptr){
                break;
            }
            count = count -> next;
        }
        count -> next = head;
        count = head;
        cnt = cnt - (k % cnt) - 1;
        for(int i = 0 ; i < cnt ; i++){
            count = count -> next;
        }
        head = count -> next;
        count -> next = nullptr;
        return head;
    }
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>ans;
        ListNode* start = head;
        while(start != nullptr){
            ans.push_back(start->val);
            start = start -> next;
        }
        int i , j ;
        for(int d = 0 ; d < ans.size()/k ; d++){
            i = d * k;
            j = i + k -1;
            while(i < j){
                swap(ans[i++],ans[j--]);
            }
        }
        start = head;
        for(i = 0 ; i < ans.size() ; i++){
            start -> val = ans[i];
            start = start -> next;
        }
        return head;
    }
};
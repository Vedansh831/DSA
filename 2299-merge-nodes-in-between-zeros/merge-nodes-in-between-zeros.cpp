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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* temp = head->next;   // Skip the first zero
        while (temp) {
            int sum = 0;
            while (temp && temp->val != 0) {
                sum += temp->val;
                temp = temp->next;
            }
            if (!temp) break;   // Safety check
            tail->next = new ListNode(sum);
            tail = tail->next;
            temp = temp->next;  // Skip the zero
        }
        return dummy->next;
    }
};
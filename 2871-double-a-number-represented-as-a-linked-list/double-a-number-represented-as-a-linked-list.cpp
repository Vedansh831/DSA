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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;

        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int carry = 0;
        ListNode* temp = head;

        while (temp) {
            int val = temp->val * 2 + carry;
            temp->val = val % 10;
            carry = val / 10;

            // If this is the last node
            if (!temp->next) {
                if (carry)
                    temp->next = new ListNode(carry);
                break;
            }

            temp = temp->next;
        }

        return reverse(head);
    }
};
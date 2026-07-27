class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);

        while (head) {
            ListNode* next = head->next;

            // Find insertion position
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < head->val) {
                prev = prev->next;
            }

            // Insert node
            head->next = prev->next;
            prev->next = head;

            head = next;
        }

        return dummy->next;
    }
};
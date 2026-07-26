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
        ListNode dummy;
        dummy.next = head;
        ListNode* prevGrp = &dummy;
        while(true){
            ListNode* kth = prevGrp;
            for(int i=0;i<k && kth;i++){
                kth = kth->next;
            }
            if(!kth) break; // All rearrangements done
            // Reverse the nodes
            ListNode* nextGrp = kth->next;
            ListNode* prev = nextGrp;
            ListNode* curr = prevGrp->next;
            while(curr!=nextGrp){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // Connect the Nodes again
            ListNode* temp = prevGrp->next;
            prevGrp->next = kth;
            prevGrp = temp;
        }
        return dummy.next;
    }
};
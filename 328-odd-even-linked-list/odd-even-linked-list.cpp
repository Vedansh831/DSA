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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(0);
        ListNode* odd = new ListNode(0);
        ListNode* temp = head;
        ListNode* tempe = even;
        ListNode* tempo = odd;
        int size=1;
        while(temp){
            if(size%2!=0){ // odd
                ListNode* c = new ListNode(temp->val);
                tempo->next = c;
                tempo=tempo->next;
                temp=temp->next;
            }
            else{ // even
                ListNode* c = new ListNode(temp->val);
                tempe->next = c;
                tempe=tempe->next;
                temp=temp->next;
            }
            size++;
        }
        tempo->next=even->next;
        return odd->next;
    }
};
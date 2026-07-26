/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                flag = true;
                break;
            }
        }
        if(flag==false) return NULL;
        else{
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }
        }
        return slow;
    }
};
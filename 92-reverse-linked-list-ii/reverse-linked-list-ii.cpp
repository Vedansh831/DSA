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
 ListNode* reverseList(ListNode* head) {
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* next = NULL ;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
 }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head ;
        int n = 1 ;
        ListNode* temp = head ;
        ListNode* a = NULL ;
        ListNode* b = NULL ;
        ListNode* c = NULL ;
        ListNode* d = NULL ;
        while(temp){
            if(n==left-1) a = temp ;
            if(n==left) b = temp ;
            if(n==right) c = temp ;
            if(n==right+1) d= temp ;
            temp=temp->next ;
            n++;
        }
        if(a) a->next = NULL ;
        c->next = NULL ;
        c = reverseList(b);
        if(a) a->next=c;
        if(d) b->next=d;
        if(a) return head;
        else return c ;
    }
};
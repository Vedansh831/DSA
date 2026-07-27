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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tempd = dummy;
        for(int i=0;i<v.size();i++){
            ListNode* c = new ListNode(v[i]);
            tempd->next=c;
            tempd=tempd->next;
        }
        head = dummy->next;
        return head;
    }
};
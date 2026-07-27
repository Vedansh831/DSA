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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* tempd = dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                tempd->next=list1;
                tempd=tempd->next;
                list1=list1->next;
            }
            else{
                tempd->next=list2;
                tempd=tempd->next;
                list2=list2->next;
            }
        }
        if(list1==NULL) tempd->next=list2;
        else tempd->next=list1;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());
            ListNode* c = merge(a, b);
            lists.push_back(c);
        }
        return lists[0];
    }
};
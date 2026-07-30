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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL) return {-1,-1};
        vector<int> ans ;
        ListNode* prev = head ;
        ListNode* point = head->next ;
        ListNode* Next = head->next->next ;
        int minD ;
        int maxD ;
        int idx=1;
        int fidx=-1;
        int sidx=-1;
        // Finding the maximum distance between two critical points;
        while(Next){
            if((prev->val>point->val && Next->val>point->val) || (prev->val<point->val && Next->val<point->val)){
                if(fidx==-1) fidx=idx;
                else sidx=idx;
            }
            prev=prev->next;
            point=point->next;
            Next=Next->next;
            idx++;
        }
        if(sidx==-1) return {-1,-1};
        maxD = sidx-fidx ;
        // Now finding the minimum distance between two critical points
        idx=1;
        fidx=-1;
        sidx=-1;
        prev=head;
        point=head->next;
        Next=head->next->next;
        while(Next){
            if((prev->val>point->val && Next->val>point->val) || (prev->val<point->val && Next->val<point->val)){
                fidx=sidx;
                sidx=idx;
                if(fidx!=-1) {
                int d = sidx-fidx;
                minD=min(minD,d);
                }
            }
            prev=prev->next;
            point=point->next;
            Next=Next->next;
            idx++;
        }
        return {minD,maxD};
        
    }
};
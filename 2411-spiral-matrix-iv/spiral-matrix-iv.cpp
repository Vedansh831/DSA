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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int o = ans.size();
        int q = ans[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = o - 1;
        int maxc = q - 1;
        int fill = 1;
        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc) {
            for (int i = minc; i <= maxc; i++) {
                if (temp == NULL)
                    return ans;
                ans[minr][i] = temp->val;
                temp = temp->next;
            }
            minr++;
            // if(minr>maxr || minc>maxc) break;
            // down
            for (int i = minr; i <= maxr; i++) {
                if (temp == NULL)
                    return ans;
                ans[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            //  if(minr>maxr || minc>maxc) break;
            // left
            for (int i = maxc; i >= minc; i--) {
                if (temp == NULL)
                    return ans;
                ans[maxr][i] = temp->val;
                temp = temp->next;
            }
            maxr--;
            //  if(minr>maxr || minc>maxc) break;
            // up
            for (int i = maxr; i >= minr; i--) {
                if (temp == NULL)
                    return ans;
                ans[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
        }
        return ans;
    }
};
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i]) st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(v[i]);
        }
        return ans;
    }
};
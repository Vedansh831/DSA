/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = 0;
        while (!q.empty()) {
            int size = q.size();
            long long nmin = q.front().second;
            long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr_node = q.front().first;
                long long curr = q.front().second - nmin;
                q.pop();
                if (i == 0) first = curr;
                if (i == size - 1) last = curr;
                if (curr_node->left) q.push({curr_node->left, curr * 2 + 1});
                if (curr_node->right) q.push({curr_node->right, curr * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        
        return (int)ans;
    }
};
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
    int mx = 0;
    // {isBST, min, max, sum}
    vector<int> solve(TreeNode* root) {
        if(root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        // Current subtree is a BST
        if(left[0] && right[0] &&
           root->val > left[2] &&
           root->val < right[1]) {
            int sum = left[3] + right[3] + root->val;
            mx = max(mx, sum);
            int minimum = min(root->val, left[1]);
            int maximum = max(root->val, right[2]);
            return {1, minimum, maximum, sum};
        }
        // Current subtree is NOT a BST
        return {0, INT_MIN, INT_MAX, 0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return mx;
    }
};
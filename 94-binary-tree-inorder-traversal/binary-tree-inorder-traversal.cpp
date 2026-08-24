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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr) {
            // No left subtree
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // Left subtree exists
            else {
                TreeNode* pred = curr->left;
                // Find inorder predecessor
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }
                // First time visiting curr
                if (pred->right == NULL) {
                    pred->right = curr;   // Create thread
                    curr = curr->left;
                }
                // Second time visiting curr
                else {
                    pred->right = NULL;   // Remove thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
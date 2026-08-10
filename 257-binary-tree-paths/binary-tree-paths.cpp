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
    void helper(TreeNode* root, vector<string>& ans, string& s) {
        if (root == NULL) return;
        // Add current node
        int len = s.size();
        s += to_string(root->val);
        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
        }
        else {
            // Add arrow before going to children
            s += "->";
            helper(root->left, ans, s);
            helper(root->right, ans, s);
        }
        // BACKTRACK
        s.resize(len);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        helper(root, ans, s);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // void rightView(TreeNode* root,vector<int>& ans){
    //     if(root==NULL) return;
    //     ans.push_back(root->val);
    //     rightView(root->right,ans);
    //     if(root->right==NULL) rightView(root->left,ans);
    // }
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->right), levels(root->left));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans) {
        if (root == NULL)
            return;
        if (curr == level) {
            ans[curr]=root->val;
            return;
        }
        nthLevel(root->left, curr + 1, level,ans);
        nthLevel(root->right, curr + 1, level,ans);
    }
    void levelOrder(TreeNode* root,vector<int>& ans) {
        int n = levels(root);
        for (int i = 0; i < n; i++) {
            nthLevel(root, 0, i, ans);
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<int> ans(n);
        levelOrder(root,ans);
        return ans;
    }
};
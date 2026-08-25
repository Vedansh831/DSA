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

    int ans;
    void helper(TreeNode* root, int& i, int k){
        if(root==NULL) return;
        helper(root->left, i, k);
        i++;
        if(k==i) ans = root->val;
        helper(root->right, i, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int a = 0;
        helper(root, a, k);
        return ans;
    }
};
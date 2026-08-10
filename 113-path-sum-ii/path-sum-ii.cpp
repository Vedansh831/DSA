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
    void helper(TreeNode* root, vector<vector<int>>& ans, int target, vector<int> v){
        if(root==NULL) return;
        if(root->right==NULL && root->left==NULL){
            if(root->val==target){
                v.push_back(root->val);
                ans.push_back(v);
            }
        }
        v.push_back(root->val);
        helper(root->left, ans, target-root->val, v);
        helper(root->right, ans, target-root->val, v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, ans, targetSum, v);
        return ans;
    }
};
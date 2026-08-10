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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void traverseRev(TreeNode* root,vector<vector<int>>& ans,int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        traverseRev(root->left,ans,level+1);
        traverseRev(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> v;
            ans.push_back(v);
        }
        traverseRev(root,ans,0);
        return ans;
    }
};
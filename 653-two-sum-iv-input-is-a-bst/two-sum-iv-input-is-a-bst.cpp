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
    void fill(TreeNode* root, unordered_set<int>& s){
        if(root==NULL) return;
        s.insert(root->val);
        fill(root->left, s);
        fill(root->right, s);
        return;
    }
    bool helper(TreeNode* root, unordered_set<int>& s, int& k){
        if(root==NULL) return false;
        int rem = k - root->val;
        if(s.find(rem)!=s.end() && rem!=root->val) return true;
        return helper(root->left, s, k) || helper(root->right, s, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        fill(root, s);

        bool ans = helper(root, s, k);
        if(ans) return true;
        return false;
    }
};
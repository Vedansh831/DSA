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
    int count=0;
    void avg(TreeNode* root, int& sum, int& n){
        if(root==NULL) return;
        sum += root->val;
        n += 1;
        avg(root->left, sum , n);
        avg(root->right, sum , n);
        return;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0, n=0;
        avg(root, sum, n);
        int a = sum/n;

        if(root->val == a) count++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return count;
    }
};
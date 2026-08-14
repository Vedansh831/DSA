/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool find(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return find(root->right,target) || find(root->left,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==p || root==q) return root;
        // else if (find(root->left,p)==true && find(root->right,q)==true) return root;
        // else if (!find(root->left,p) && !find(root->right,q)) return root;
        // else if (find(root->left,p)==true && !find(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        // else return lowestCommonAncestor(root->right,p,q);
        //Better Method
        if(root==p || root==q) return root;
        if(root->val > p->val && root->val < q->val) return root;
        else if(root->val < p->val && root->val > q->val) return root;
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
};
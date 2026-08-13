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
    TreeNode* helper(vector<int> pre, int prelo, int prehi, vector<int> in, int inlo, int inhi){
        if(prelo > prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i = inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break ;
            i++ ;
        }
        int leftdistance = i - inlo ;
        int rightdistance = inhi - i ;
        root->left = helper(pre,prelo+1,prelo+leftdistance,in,inlo,i-1);
        root->right = helper(pre,prelo+leftdistance+1,prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};
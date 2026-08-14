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
    TreeNode* helper(vector<int>& pre, int prelo, int prehi, vector<int>& post, int postlo, int posthi){
        if(prelo>prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        // Left subtree root is next in preorder
        int leftRoot = pre[prelo + 1];
        // Find left root in postorder
        int i = postlo;
        while (post[i] != leftRoot) i++;
        int leftDistance = i - postlo ;
        root->left=helper(pre,prelo+1,prelo+leftDistance+1,post,postlo,postlo+leftDistance);
        root->right=helper(pre,prelo+leftDistance+2,prehi,post,postlo+leftDistance+1,posthi-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, postorder, 0, n-1);
    }
};
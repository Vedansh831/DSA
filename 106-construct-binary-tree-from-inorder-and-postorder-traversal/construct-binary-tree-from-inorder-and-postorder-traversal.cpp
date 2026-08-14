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
    TreeNode* helper(vector<int>& in, int inlo, int inhi, vector<int>& post, int postlo, int posthi){
        if(inlo > inhi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        int i = inlo;
        while(i<inhi){
            if(in[i] == post[posthi]) break;
            i++;
        }
        int leftdistance = i - inlo;
        int rightdistance = inhi - i;
        root->left = helper(in, inlo, i-1, post, postlo, postlo+leftdistance-1);
        root->right = helper(in, i+1, inhi, post, postlo+leftdistance, posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder, 0, n-1, postorder, 0, n-1);
    }
};
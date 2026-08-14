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
    TreeNode* helper(vector<int> inorder, int inlo, int inhi,vector<int> postorder, int postlo, int posthi){
        if(inlo>inhi) return NULL;
        TreeNode* root = new TreeNode(postorder[posthi]);
        // if(inhi==inlo) return root;
        int i = inlo ;
        while(i<=inhi){ //Find the root
            if(inorder[i]==postorder[posthi]) break;
            i++;
        }
        int leftDistance = i-inlo;
        int rightDistance = inhi-i;
        root->left=helper(inorder,inlo,i-1,postorder,postlo,postlo+leftDistance-1);
        root->right=helper(inorder,i+1,inhi,postorder,postlo+leftDistance,posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder,0,n-1,postorder,0,n-1);
    }
};
class Solution {
public:
    int mx = INT_MIN;

    int helper(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftSum = max(0, helper(root->left));
        int rightSum = max(0, helper(root->right));

        // Path passing through root
        mx = max(mx, leftSum + rightSum + root->val);

        // Path that can be extended to parent
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return mx;
    }
};
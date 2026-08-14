class Solution {
public:
    // Store all values
    void helper(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }
    // Build balanced BST from sorted array
    TreeNode* construct(vector<int>& v, int l, int r) {
        if(l > r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = construct(v, l, mid - 1);
        root->right = construct(v, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        // Get all values
        helper(root, v);
        // Sort them
        sort(v.begin(), v.end());
        // Construct balanced BST
        return construct(v, 0, v.size() - 1);
    }
};
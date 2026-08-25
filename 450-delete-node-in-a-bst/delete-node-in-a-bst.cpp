class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        // Search for the key
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: Leaf node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // Case 2: Only right child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: Only left child
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            // Find inorder predecessor
            TreeNode* pred = root->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            // Copy predecessor value
            root->val = pred->val;
            // Delete predecessor from left subtree
            root->left = deleteNode(root->left, pred->val);
        }
        return root;
    }
};
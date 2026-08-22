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
    TreeNode* mark(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int target){
        TreeNode* tar = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val==target){
                tar = curr;
            }

            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return tar;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* tar = mark(root, parent, start);
        queue<TreeNode*> q;
        q.push(tar);
        unordered_map<TreeNode*, bool> visited;
        visited[tar] = true;
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // Right child
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // Parent
                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        return ans-1;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> st1; //left to right
        stack<TreeNode*> st2; //right to left
        if(root==NULL) return ans; st1.push(root);
        while(st1.size() || st2.size()){
            vector<int> v;
            //left to right
            while(st1.size()>0){
                TreeNode* temp = st1.top();
                st1.pop();
                v.push_back(temp->val);

                if(temp->left) st2.push(temp->left);
                if(temp->right) st2.push(temp->right);
            }
            if(v.size()>0) ans.push_back(v);
            v.clear();
            //right to left
            while(st2.size()>0){
                TreeNode* temp = st2.top();
                st2.pop();
                v.push_back(temp->val);
                if(temp->right) st1.push(temp->right);
                if(temp->left) st1.push(temp->left);
            }
            if(v.size()>0) ans.push_back(v);
            v.clear();
        }
        return ans;   
    }
};
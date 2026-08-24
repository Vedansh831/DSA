class Solution {
public:
    void flatten(TreeNode* root) {
        //By Morris Traversal jaisa method ,, unlike other two methods here the space complexicity is O(1)
        if(root==NULL) return ;
        TreeNode* curr = root ;
        while(curr!=NULL){
            if(curr->left!=NULL){
                //save the right
                TreeNode* r = curr->right ;
                curr->right = curr->left ;
                //finding predecessor
                TreeNode* pred = curr->left ;
                while(pred->right!=NULL) pred = pred->right ;
                //linking
                pred->right = r ;
                curr = curr->left ;
            }
            else{
                curr = curr->right ;
            }
            }
            TreeNode* temp = root ;
            while(temp->right!=NULL){
                temp->left = NULL ;
                temp = temp->right;
        }
        // return;
    }
};
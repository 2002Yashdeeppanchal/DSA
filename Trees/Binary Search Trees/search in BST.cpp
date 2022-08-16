TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr and root->val!=val){
            root=root->val>val ? root->left : root->right;
        }
        return root;
    }

bool helper(TreeNode* root,long long int minrange,long long int maxrange){
        if(root==nullptr){
            return true;
        }
        if(root->val<=minrange or root->val>=maxrange){
            return false;
        }
        return (helper(root->left,minrange,root->val) and helper(root->right,root->val,maxrange));
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_LONG_MIN , LONG_LONG_MAX);
    }
};

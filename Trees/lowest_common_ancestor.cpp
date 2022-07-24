
TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left=helper(root->left,p,q);
        TreeNode* right=helper(root->right,p,q);
        if(left!=nullptr and right!=nullptr){
            return root;
        }
        if(left==nullptr and right!=nullptr){
            return right;
        }
        if(left!=nullptr and right==nullptr){
            return left;
        }
        return nullptr;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }

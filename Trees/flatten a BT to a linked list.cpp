
//recursive solution

void helper(TreeNode* &node,TreeNode* &prev){
        if(node==nullptr){
            return;
        }
        helper(node->right,prev);
        helper(node->left,prev);
        node->right=prev;
        node->left=nullptr;
        prev=node;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* prev=nullptr;
        helper(root,prev);
    }



//using morris traversal si technique to optimize space complexity

void flatten(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        while(curr!=nullptr){
            if(curr->left!=nullptr){
                prev=curr->left;
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }

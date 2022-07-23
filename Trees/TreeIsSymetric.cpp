
    Mirror property is    left == right and right == left
    pre-order traversal on root->left subtree, (root, left, right)
     modified pre-order traversal on root->right subtree, (root, right, left) 
     compare the node val's if they are the same 
     Do both traversals at the same time
     if left is null or right is null, then both sides must match and return true (base case)



    bool helper(TreeNode* left,TreeNode* right){
        if(left==nullptr or right==nullptr){
            return left==right;
        }
        if(left->val!=right->val){
            return false;
        }
        return helper(left->left,right->right) and  helper(left->right,right->left);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return root==nullptr or helper(root->left,root->right);
    }

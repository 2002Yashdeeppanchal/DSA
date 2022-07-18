//using recursion
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int leftheight=maxDepth(root->left);
        int rightheight=maxDepth(root->right);
        return 1+max(leftheight,rightheight);
    }


//using level order traversal
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return ans;
    }

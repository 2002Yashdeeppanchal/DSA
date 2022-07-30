same code hai bs bhai thoda sa change hai bs previous problem se(preorder and inorder se) bs isme last me lie krti hai root


TreeNode* helper(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>& m){
        //boundary check
        if(poststart>postend or instart>inend)return nullptr;
        
        TreeNode* root=new TreeNode(postorder[postend]);
        
        int inmap=m[root->val];
        
        int numleft=inmap-instart;
        
        root->left=helper(postorder,poststart,poststart+numleft-1,inorder,instart,inmap-1,m);
        root->right=helper(postorder,poststart+numleft,postend-1,inorder,inmap+1,inend,m);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size()!=postorder.size())return NULL;
        
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }

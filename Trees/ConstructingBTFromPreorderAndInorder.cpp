TreeNode* helper(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& m){
        //check for boundary case
        if(prestart>preend or instart>inend)return nullptr;
        //create a new node;
        TreeNode* root=new TreeNode(preorder[prestart]);
        //this root node is where in the inorder list
        int inmap=m[root->val];
        //left subtree contain how many nodes
        int numleft=inmap-instart;
        //now same do for left tree as well as right tree and attach to the root
        root->left=helper(preorder,prestart+1,prestart+numleft,inorder,instart,inmap-1,m);
        root->right=helper(preorder,prestart+numleft+1,preend,inorder,inmap+1,inend,m);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        //keep all the inorder elements in a hashmap so that we can determine the index of the root
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }

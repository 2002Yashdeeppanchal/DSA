as we know that a unique BT can be created using inorder and preorder/postorder we are given preorder so sort it we get inorder
that it


tc is nlogn for sorting and n for creating 


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
    
    
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        TreeNode* root=buildTree(preorder,inorder);
        return root;
    }






idea is that we have done checking a bt is bst or not in that we assign a range to every node in this also we declare a range kinda thing
in this we use only mxrange okay the root must lie less than INT_MAX and then we move left then this left node's range must be less than its parent
means that if we move left range is less than nodes val
and if we move right then range is INT_MAx


do a dry run or watch video 


TreeNode* helper(vector<int>& preorder,int &i,int mxrange){
        if(i==preorder.size() or preorder[i]>mxrange)return nullptr;
        TreeNode* node=new TreeNode(preorder[i]);
        i++;
        node->left=helper(preorder,i,node->val);
        node->right=helper(preorder,i,mxrange);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,INT_MAX);
    }







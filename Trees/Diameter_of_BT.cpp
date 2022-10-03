O(N^2) sol can be as we traversal all the nodes and while traversing we find maxDepth on its left as well as maxDepth on its 
right (we are considering this node as the curving point of the path) and update the longestpath by lh+rh   and do this for 
all the nodes after that longestpath stores the ans




but think why we cal the left heigh and right height every time we simply update the maxDepth code and hence we find 
the ans while finding the maxDepth so its a O(N) sol

  int maxDepth(TreeNode* root,int& diameter){
        if(root==NULL){
            return 0;
        }
        int lh=maxDepth(root->left,diameter);
        int rh=maxDepth(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(rh,lh);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int h=maxDepth(root,diameter);
        return diameter;
    }

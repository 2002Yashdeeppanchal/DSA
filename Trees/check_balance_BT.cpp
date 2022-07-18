//O(n^2) sol
checking every node

  int maxDepth(TreeNode* root) {//using level order traversal
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
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        //simply cal the left height and right height of every node if their diff is greater than one then false;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        
        if(abs(lh-rh)>1)return false;
        
        //check for left as well as right child or every node if any one of them return false then simply return false
        if(!isBalanced(root->left) or !isBalanced(root->right))return false;
        
        return true;
    }




O(N) sol maxDepth nikalna aata hi hai uska hi modification hai bs height cal krte krte check bhi krte rho it left height or right height ka difference

int maxDepth(TreeNode* root){
        if(root==NULL)return 0;
        
        int lh=maxDepth(root->left);
        
        //while cal lh if we encounter that its left-right > 1 na to return -1;
        if(lh==-1)return -1;
        
        int rh=maxDepth(root->right);
        
        //same as lh
        if(rh==-1)return -1;
        
        //normal na
        if(abs(lh-rh)>1)return -1;
        
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        //when we compute the max height of a BT then we first check its left height and its right height using recursion as well as using level order so now simply check their difference bro that's it done na
        //ab thode se changes krne hai bs height cal krne pr agr BT balanced nikalta hai last me to height return kr denge ni to -1 theek hai
        
        return maxDepth(root)!=-1;
        
    }

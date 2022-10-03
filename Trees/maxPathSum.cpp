  
its just a variation of the problem we did before that is diameter of a binary tree for that problem we return maxdepth of right
and left in this problem we return sum


    int solve(TreeNode* root,int &ans){
        if(root==NULL)return 0;
        
        //cal the left sum same as we find the depth of left tree we cal sum
        int leftsum=solve(root->left,ans);
        
        //if the sum is -ve then we take 0 insteed
        if(leftsum<0)leftsum=0;
        
        //same as left
        int rightsum=solve(root->right,ans);
        
        if(rightsum<0)rightsum=0;
        
        //we update the ans by root ki val and left ka sum and right ka sum here also we are considering the root as the 
        //curving point of the path
        ans=max(ans,root->val+leftsum+rightsum);
        
        //vhi ki apn jis node pr hai usse aage konsa path le to agr left ka sum jyda hai to left me ni to right me 
        return (root->val+max(leftsum,rightsum));
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }

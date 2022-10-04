int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long long int>>q;//node or index
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<sz;i++){
                int id=q.front().second-mini;//hr baar mini one ni hoga ye to clear hai na, sbse left most vala hai mini 
                                             //uska index kuch bhi ho skta hai
                if(i==0)first=id;
                if(i==sz-1)last=id;
                if(q.front().first->left){
                    q.push({q.front().first->left,(long long)2*id+1});
                }
                if(q.front().first->right){
                    q.push({q.front().first->right,(long long)2*id+2});
                }
                q.pop();
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }

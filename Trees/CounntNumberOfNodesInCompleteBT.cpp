//level order se
int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans+=sz;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }











//complete BT ki property use krke

int findleftht(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->left;
        }
        return ht;
    }
    
    int findrightht(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->right;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=findleftht(root);
        int rh=findrightht(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }

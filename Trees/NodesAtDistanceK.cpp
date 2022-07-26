void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentnode){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    parentnode[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parentnode[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parentnode;
        markparent(root,parentnode);
        
        queue<TreeNode*>q;
        q.push(target);
        
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        
        int cnt=0;
        
        while(!q.empty()){
            int sz=q.size();
            if(cnt++==k)break;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL and visited[curr->left]==false){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=NULL and visited[curr->right]==false){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parentnode[curr]!=NULL and visited[parentnode[curr]]==false){
                    q.push(parentnode[curr]);
                    visited[parentnode[curr]]=true;
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }

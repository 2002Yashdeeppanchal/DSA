simply level order me hi ek check lga do ki agr apn right to left aane vale hai to peeche se insert kro elements

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool islefttoright=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int>row(sz);
            for(int i=0;i<sz;i++){
                int index=islefttoright ? i : sz-i-1;  //if left to right true then we insert normally aage se agr false to reverse me
                row[index]=q.front()->val;
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            islefttoright=!islefttoright;
            ans.push_back(row);
        }
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>sol=levelOrder(root);
        return sol;
    }

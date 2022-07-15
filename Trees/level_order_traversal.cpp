vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>temp;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                temp.push_back(q.front()->val);
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
}

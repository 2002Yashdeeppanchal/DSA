implementation is bit tricky but the sole concept is easy to understand we assign every node a vertical and level then for each vertical their are several level so if a level has overlapping nodes then sort it


vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;//Node,vertical,level
        map<int,map<int,multiset<int>>>m;//vertical,level,values of nodes in sorted order
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node_ver_lev=q.front();
            q.pop();
            TreeNode* temp=node_ver_lev.first;
            int vertical=node_ver_lev.second.first;
            int level=node_ver_lev.second.second;
            m[vertical][level].insert(temp->val);//map me vertical level ke according node ki val insert kr do multiset me
            if(temp->left){
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        vector<int>ran;
        for(auto a : m){
            for(auto b : a.second){
                for(auto c : b.second){//copying multiset items in a vector
                    ran.push_back(c);
                }
            }
            ans.push_back(ran);
            ran.clear();
        }
        return ans;
        
    }

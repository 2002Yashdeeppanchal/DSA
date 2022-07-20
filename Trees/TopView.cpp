we assign vertical to each node and do level order traversal and keep a map<int,int> first int denotes the vertical and second the val of the node and if vertical already exist then we dont update


vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(!root)return ans;
    queue<pair<TreeNode<int>*,int>>q;//node and vertical
    q.push({root,0});
    map<int,int>m;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        if(m.find(p.second)==m.end())m[p.second]=p.first->val;//if the node corresponding to the vertical is not there in the map then we first time visit it so update
        if(p.first->left){
            q.push({p.first->left,p.second-1});
        }
        if(p.first->right){
            q.push({p.first->right,p.second+1});
        }
    }
    for(auto a : m){
        ans.push_back(a.second);
    }
    return ans;
}

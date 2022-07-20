vector<int> getTopView(BinaryTreeNode<int> *root) {
    vector<int>ans;
    if(!root)return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;//node and vertical
    q.push({root,0});
    map<int,int>m;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        m[p.second]=p.first->data;//isme kuch bhi ho phle se ho map me ya na ho apn to update kr do kyuki apn neeche se dekh rhe hai last vala phle dikhega
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


vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int>ans=getTopView(root);
    return ans;    
}

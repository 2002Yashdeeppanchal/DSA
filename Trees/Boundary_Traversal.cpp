
bool isleaf(TreeNode<int>* root){
    return (root->right==NULL and root->left==NULL);
}

void addleftboundary(TreeNode<int>* root,vector<int> &ans){
    TreeNode<int>* curr=root->left;
    while(curr){
        if(!isleaf(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}

void addleafnodes(TreeNode<int>* root,vector<int> &ans){
    if(isleaf(root)){
        ans.push_back(root->data);
    }
    if(root->left)addleafnodes(root->left,ans);
    if(root->right)addleafnodes(root->right,ans);
}

void addrightboundary(TreeNode<int>* root,vector<int> &ans){
    vector<int>temp;
    TreeNode<int>* curr=root->right;
    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right)curr=curr->right;
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    
    //first we take left boundry then we take the leaf nodes and then take the right boundary in the reverse fashion
    
    //by chance if our root is null 
    vector<int>ans;
    
    if(!root)return ans;
    
    if(!isleaf(root))ans.push_back(root->data);
    
    addleftboundary(root,ans);
    
    addleafnodes(root,ans);
    
    addrightboundary(root,ans);
    
    return ans;
    
}




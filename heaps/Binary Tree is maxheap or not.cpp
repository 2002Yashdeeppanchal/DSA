int cnt(struct Node* root,int& ans){
        if(root==nullptr){
            return 0;
        }
        ans++;
        cnt(root->left,ans);
        cnt(root->right,ans);
        return ans;
    }
    
    bool iscbt(struct Node* root,int index,int cnt){
        if(root==nullptr){
            return true;
        }
        if(index>=cnt){
            return false;
        }
        bool left=iscbt(root->left,2*index+1,cnt);
        bool right=iscbt(root->right,2*index+2,cnt);
        return (left and right);
    }
    
    bool ismaxheap(struct Node* root){
        
        if(root->right==nullptr and root->left==nullptr){
            return true;
        }
        
        if(root->right==nullptr){
            return (root->left->data < root->data);
        }
        else{
            bool left=ismaxheap(root->left);
            bool right=ismaxheap(root->right);
            return (left and right and (root->right->data < root->data and root->left->data < root->data));
        }
        
    }
    
    bool isHeap(struct Node* tree) {
        
        int index=0;
        int totalnodes=0;
        if(iscbt(tree,index,cnt(tree,totalnodes)) and ismaxheap(tree)){
            return true;
        }
        else{
            return false;
        }
        
    }


Self Notes 📜:
🥥 if both children sum is less than parent, make children's value to parent's value.
🥥 if both children values sum is greater than or equal to parent, make parent's value to children's sum.
🥥 recursively go left and right. Traversal type: DFS.
🥥 when coming back up the tree, take children sum and replace it in parent.
🥥 at any point we reach null, just return (base case)
🥥 Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.




void changeTree(BinaryTreeNode < int > * root) {
    if(root==nullptr){
        return;
    }
    int childsum=0;
    if(root->left){
        childsum+=root->left->data;
    }
    if(root->right){
        childsum+=root->right->data;
    }
    if(childsum>=root->data){
        root->data=childsum;
    }
    else{
        if(root->left){
            root->left->data=root->data;
        }
        if(root->right){
            root->right->data=root->data;
        }
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int tot=0;//left gye right gye ab root ko dono ka sum bna do bhai
    if(root->left){
        tot+=root->left->data;
    }
    if(root->right){
        tot+=root->right->data;
    }
    if(root->left or root->right){//leaf nodes ko chdne ke liye
        root->data=tot;
    }
}  

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void inorder(BinaryTreeNode<int> *node,vector<int> &ans){
    if(node==NULL)return;
    inorder(node->left,ans);
    ans.push_back(node->data);
    inorder(node->right,ans);
}

void preorder(BinaryTreeNode<int> *node,vector<int> &ans){
    if(node==NULL)return;
    ans.push_back(node->data);
    preorder(node->left,ans);
    preorder(node->right,ans);
}

void postorder(BinaryTreeNode<int> *node,vector<int> &ans){
    if(node==NULL)return;
    postorder(node->left,ans);
    postorder(node->right,ans);
    ans.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans(3);
    inorder(root,ans[0]);
    preorder(root,ans[1]);
    postorder(root,ans[2]);
    return ans;
}

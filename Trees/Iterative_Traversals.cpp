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
#include<bits/stdc++.h>
vector<int>preorder(BinaryTreeNode<int>* root){
    vector<int>temp;
    if(root==NULL)return temp;
    stack<BinaryTreeNode<int>*>st;
    st.push(root);
    while(!st.empty()){
        BinaryTreeNode<int>* node=st.top();
        temp.push_back(node->data);
        st.pop();
        if(node->right!=NULL){
            st.push(node->right);
        }
        if(node->left!=NULL){
            st.push(node->left);
        }
    }
    return temp;
}

vector<int>inorder(BinaryTreeNode<int>* root){
    vector<int>temp;
    if(root==NULL)return temp;
    stack<BinaryTreeNode<int>*>st;
    BinaryTreeNode<int>* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty())break;
            node=st.top();
            temp.push_back(node->data);
            st.pop();
            node=node->right;
        }
    }
    return temp;
}

vector<int>postorder_2stacks(BinaryTreeNode<int>* root){
    vector<int>temp;
    if(root==NULL)return temp;
    stack<BinaryTreeNode<int>*>stone,sttwo;
    stone.push(root);
    while(!stone.empty()){
        root=stone.top();
        stone.pop();
        sttwo.push(root);
        if(root->left!=NULL){
            stone.push(root->left);
        }
        if(root->right!=NULL){
            stone.push(root->right);
        }
    }
    while(!sttwo.empty()){
        temp.push_back(sttwo.top()->data);
        sttwo.pop();
    }
    return temp;
}


vector<int>postorder_1stack(BinaryTreeNode<int>* root){
    vector<int>ans;
    stack<BinaryTreeNode<int>*>st;
    BinaryTreeNode<int>* curr=root;
    while(curr!=NULL or !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            BinaryTreeNode<int>* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() and temp==st.top()->right){
                    temp=st.top();
                    ans.push_back(temp->data);
                    st.pop();
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans(3);
    ans[1]=preorder(root);
    ans[0]=inorder(root);
    ans[2]=postorder_1stack(root);
    return ans;
}

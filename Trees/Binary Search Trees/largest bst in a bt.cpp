#include<bits/stdc++.h>
#define val data

class ContainerForNode{//this act as a three variable container which contain size,mxnode,minnode
    public : 
    int maxsize,maxnode,minnode;
    
    ContainerForNode(int mnnode,int mxnode,int size){
        this->maxsize=size;
        this->maxnode=mxnode;
        this->minnode=mnnode;
    }
};

ContainerForNode largestBSThelper(TreeNode<int>* root){
    if(root==nullptr){
        return ContainerForNode(INT_MAX,INT_MIN,0);
    }
    
    auto left=largestBSThelper(root->left);
    auto right=largestBSThelper(root->right);
    
    if(left.maxnode < root->val and root->val < right.minnode){
        //valid bst
        return ContainerForNode(min(root->val, left.minnode), max(root->val, right.maxnode), 
                            left.maxsize + right.maxsize + 1);
    }
    
    //if not valid bst
    return ContainerForNode(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    
}

int largestBST(TreeNode<int>* root) 
{
    auto cnt=largestBSThelper(root);
    return cnt.maxsize;
}

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
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    stack<pair<BinaryTreeNode<int>*,int>>st;
    vector<vector<int>>ans(3);
    if(root==NULL)return ans;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        //if the num is 1 then it should add in pre list
        if(it.second==1){
            ans[1].push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        
        //if the num is 2 then inorder list
        else if(it.second==2){
            ans[0].push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        
        //if 3 then postorder and remember this time we pop it out
        else if(it.second==3){
            ans[2].push_back(it.first->data);
        }
    }
    return ans;
}

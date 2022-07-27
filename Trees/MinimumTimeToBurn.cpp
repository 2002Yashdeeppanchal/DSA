
self notes
->first mark all the parent pointers of all nodes to traverse in upward also
->find the target node from which we have to burn the tree (mene preorder se kiya hai find)
->then this problem is same as the print all the nodes from a node whose distance is K
->traverse left,right,up for a set of nodes(level order) and if any of nodes kill any other node then ans++

#include<bits/stdc++.h>

void markparent(BinaryTreeNode<int>* root,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &parent){
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            BinaryTreeNode<int>* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
}

BinaryTreeNode<int>* findnode(BinaryTreeNode<int>* node,int target){
    if(node==NULL)return NULL;
    if(node->data==target){
        return node;
    }
    BinaryTreeNode<int>*left=findnode(node->left,target);
    BinaryTreeNode<int>*right=findnode(node->right,target);
    
    if(left!=NULL and right==NULL){
        return left;
    }
    
    if(left==NULL and right!=NULL){
        return right;
    }
    
    return NULL;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parent;
    markparent(root,parent);
    
    BinaryTreeNode<int>* node=findnode(root,start);
    
    queue<BinaryTreeNode<int>*>q;
    q.push(node);
    
    unordered_map<BinaryTreeNode<int>*,bool>visited;
    visited[node]=true;
    
    int ans=0;
    bool hit=false;
    
    while(!q.empty()){
        int sz=q.size();
        hit=false;
        for(int i=0;i<sz;i++){
            BinaryTreeNode<int>* curr=q.front();
            q.pop();
            if(curr->left!=NULL and visited[curr->left]==false){
                hit=true;
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right!=NULL and visited[curr->right]==false){
                hit=true;
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent[curr]!=NULL and visited[parent[curr]]==false){
                hit=true;
                q.push(parent[curr]);
                visited[parent[curr]]=true;
            }
        }
        if(hit){
            ans++;
        }
    }
    
    return ans;  
  
}

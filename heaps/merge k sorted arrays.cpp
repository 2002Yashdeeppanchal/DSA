#include <bits/stdc++.h>

class node{
  public:
    int data;
    int row;
    int col;
   
   node(int val,int row,int col){
       this->data=val;
       this->row=row;
       this->col=col;
   }
};

class comparator{
  public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<node*,vector<node*>,comparator>p;
    
    //push all the first element of all arrs
    
    for(int i=0;i<k;i++){
        node* n=new node(arr[i][0],i,0);
        p.push(n);
    }
    
    vector<int>ans;
    //push smallest element till and push next element of same arr in which the smallest element occur
    while(p.size() > 0){
        node* temp=p.top();
        ans.push_back(temp->data);
        p.pop();
        int r=temp->row;
        int c=temp->col;
        
        if(c+1 < arr[r].size()){
            node* n=new node(arr[r][c+1],r,c+1);
            p.push(n);
        }
    }
    
    return ans;
    
}

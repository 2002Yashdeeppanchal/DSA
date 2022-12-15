class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]);//this is the path compression do a dry run
    }

    void unionbyrank(int u,int v){
        int upu=findUparent(u);
        int upv=findUparent(v);
        if(upu==upv){//if both nodes have same ultimate parent means they belong to same component
            return;
        }
        if(rank[upu] < rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upv] < rank[upu]){
            parent[upv]=upu;
        }
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
    }

    void unionbysize(int u,int v){
        int upu=findUparent(u);
        int upv=findUparent(v);
        if(upu==upv){//if both nodes have same ultimate parent means they belong to same component
            return;
        }
        if(size[upu] < size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu]; 
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};


class Solution {
    private:
        bool isvalid(int row,int col,int n){
            return (row>=0 and row<n and col>=0 and col<n);
        }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DisjointSet ds(n*n);
        
        //connect all the ones (making components) in ds
        
        int delrow[]={0,-1,+1,0};
        int delcol[]={-1,0,0,+1};
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    for(int k=0;k<4;k++){
                        int nrow=row+delrow[k];
                        int ncol=col+delcol[k];
                        if(isvalid(nrow,ncol,n) and grid[nrow][ncol]==1){
                            int nodeno=(row*n)+col;
                            int adjnodeno=(nrow*n)+ncol;
                            ds.unionbysize(nodeno,adjnodeno);
                        }
                    }
                }
            }
        }
        
        //brute forcing (traverse all the zeros and try to make it one and find the maximum connected components)
        set<int>components;
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    for(int i=0;i<4;i++){
                        int nrow=row+delrow[i];
                        int ncol=col+delcol[i];
                        if(isvalid(nrow,ncol,n) and grid[nrow][ncol]==1){
                            int nodeno=(nrow*n)+ncol;
                            int ultimateparent=ds.findUparent(nodeno);
                            components.insert(ultimateparent);
                        }
                    }
                    int totalsize=0;
                    for(auto it : components){
                        totalsize+=ds.size[it];
                    }
                    totalsize++;//self zero ka jo ab one bnne vala hai
                    ans=max(ans,totalsize);
                }
                components.clear();
            }
        }
        
        //if the whole matrix is full of ones and no 0 are there 
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUparent(i)]);
        }
        
        
        return ans;
        
    }
};

class DisjointSet{
    vector<int>rank,parent,size;
public:
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
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow=0;
        int maxcol=0;
        for(auto it : stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        for(auto it : stones){
            int rowno=it[0];
            int colno=it[1]+maxrow+1;
            ds.unionbysize(rowno,colno);
        }
        set<int>st;
        
        for(auto it : stones){
            st.insert(ds.findUparent(it[0]));
            st.insert(ds.findUparent(it[1]+maxrow+1));
        }
        
        int ans=st.size();
        
        return n-ans;
        
    }
};

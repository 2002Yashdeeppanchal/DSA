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
    private:
    bool validcheck(int row,int col,int n,int m){
        return (row>=0 and row<n and col>=0 and col<m);
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        
        vector<int>ans;
        int cnt=0;
        
        for(auto i : operators){
            int row=i[0];
            int col=i[1];
            
            int blocknum=(row*m)+col;
            
            if(vis[row][col]==1){//already edge created hai
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;//assume it as a single compo
            
            int delrow[]={0,-1,+1,0};
            int delcol[]={-1,0,0,+1};
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                int neighbourblocknum = (nrow*m)+ncol;
                if(vis[nrow][ncol]==1){
                    if(validcheck(nrow,ncol,n,m)){
                        if(ds.findUparent(blocknum) != ds.findUparent(neighbourblocknum)){//if node and adjnode has two different ultimate parents 
                            cnt--;
                            ds.unionbysize(blocknum,neighbourblocknum);//connnet them
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
            
        }
        
        return ans;
        
        
    }
};

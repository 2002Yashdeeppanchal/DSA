
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
    int regionsBySlashes(vector<string>& grid) {
        

        //creating dsu
        int n=grid.size();
        DisjointSet ds((n+1)*(n+1));

        //creating links of boundary first row
        for(int i=0;i<=n;i++){
            cout<<i<<" ";
            ds.unionbysize(0,i);
        }
        cout<<endl;
        //first col
        int f=n*(n+1);
        for(int i=n+1;i<=f;i+=(n+1)){
            cout<<i<<" ";
            ds.unionbysize(0,i);
        }
        cout<<endl;
        //last row
        f=n*(n+1);
        for(int i=f;i<=(f+n);i++){
            cout<<i<<" ";
            ds.unionbysize(0,i);
        }
        cout<<endl;
        //last col
        for(int i=n;i<(n+1)*(n+1);i+=(n+1)){
            cout<<i<<" ";
            ds.unionbysize(0,i); 
        }
        cout<<endl;

        int ans=1;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    int p1=(i*(n+1))+j+1;
                    int p2=((i+1)*(n+1))+j;
                    cout<<i<<" "<<j<<" ";
                    cout<<"p1p2 "<<p1<<" "<<p2<<endl;
                    if(ds.findUparent(p1)==ds.findUparent(p2)){
                        ans++;
                    }
                    else{
                        ds.unionbysize(p1,p2);
                    }
                }
                else if(grid[i][j]=='\\'){
                    int p1=(i*(n+1))+j;
                    int p2=((i+1)*(n+1))+j+1;
                    if(ds.findUparent(p1)==ds.findUparent(p2)){
                        ans++;
                    }
                    else{
                        ds.unionbysize(p1,p2);
                    }
                    // i++;
                }
            }
        }


        return ans;




    }
};

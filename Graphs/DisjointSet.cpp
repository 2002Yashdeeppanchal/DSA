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


void solve(){ 
    DisjointSet d(7);
    d.unionbysize(1,2);
    d.unionbysize(2,3);
    d.unionbysize(4,5);
    d.unionbysize(6,7);
    d.unionbysize(5,6);

    if(d.findUparent(3)==d.findUparent(7)){
        cout<<"belong to same component";
    }
    else{
        cout<<"not belong to same component";
    }
    cout<<nline;

    
    d.unionbysize (3,7);

    if(d.findUparent(3)==d.findUparent(7)){
        cout<<"belong to same component";
    }
    else{
        cout<<"not belong to same component";
    }
    cout<<nline;

}   
 

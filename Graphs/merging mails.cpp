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


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        int n=accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string,int>mapmailnode;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmailnode.find(mail) == mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                else{
                    ds.unionbysize(mapmailnode[mail],i);
                }
            }
        }
        
        vector<vector<string>> ans(n);
        
        for(auto it : mapmailnode){
            string mail=it.first;
            int node=ds.findUparent(it.second);
            ans[node].push_back(mail);
        }
        
        vector<vector<string>> finalans;
        
        for(int i=0;i<n;i++){
            if(ans[i].size()==0){
                continue;
            }
            sort(ans[i].begin(),ans[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : ans[i]){
                temp.push_back(it);
            }
            finalans.push_back(temp);
        }
        
        return finalans;
        
        
    }
};

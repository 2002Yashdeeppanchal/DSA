class Solution {
    
    private:
        void dfs(int node,vector<int> adjls[],vector<int> &vis){
            vis[node]=1;
            for(auto i : adjls[node]){
                if(vis[i]==0){
                    dfs(i,adjls,vis);
                }
            }
        }
    
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        
        //first we convert adj matrix into adj list
        vector<int>adjls[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1 and i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(v,0);
        int cnt=0;
        
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjls,vis);//each dfs call mark all neighbours of node i as one 
            }
        }
        
        return cnt;
        
    }
};

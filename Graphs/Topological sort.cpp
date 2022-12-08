class Solution {
    
    private:
    bool dfs(int node,int vis[],int pathvis[],vector<int> adj[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)){
                    return true;
                }
            }
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        
        int vis[v]={0};
        int pathvis[v]={0};
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj);
            }
        }
        
        vector<int> safenodes;
        
        for(int i=0;i<v;i++){
            if(!pathvis[i]){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
        
    }
};

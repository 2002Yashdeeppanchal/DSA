class Solution {
private:
    
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis)==true){
                    return true;
                }
            }
          //if this node is previously vis and in the same path
            else if(pathvis[it]==1){
                return true;
            }
        }
        
        pathvis[node]=0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

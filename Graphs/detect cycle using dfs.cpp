class Solution {
private:
    bool dfs(int node,int parent,int vis[],vector<int> adj[]){
        vis[node]=1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i,node,vis,adj)){
                    return true;
                }
            }
            else if(i!=parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
    private:
        void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &ls){
            vis[node]=1;
            ls.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it,adj,vis,ls);
                }
            }
        }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>vis(v);
        for(auto i : vis){
            i=0;
        }
        int start=0;
        vis[start]=1;
        
        vector<int>ls;
        dfs(start,adj,vis,ls);
        
        return ls;
        
    }
};

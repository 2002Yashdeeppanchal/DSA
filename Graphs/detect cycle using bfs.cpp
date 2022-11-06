class Solution {
private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;//{to,from}
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(i!=parent){//as parent's vis is also tru na but we want neighbour only parent se to aae hai na
                    return true;
                }
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
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int v,int e, int src){
        
        //get the graph ready
        vector<int> adj[v];
        for(auto i : edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //do the distance stuff and bfs
        vector<int> dist(v,1e9);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        
      //tc - O(v+2e) same as bfs
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<v;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};

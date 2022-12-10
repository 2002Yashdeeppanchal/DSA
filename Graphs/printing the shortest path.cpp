class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        //gettint the graph ready
        vector<pair<int,int>>adj[n+1];
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int neighbour=it.first;
                int wt=it.second;
                if(dis + wt < dist[neighbour]){
                    dist[neighbour]=dis + wt;
                    parent[neighbour]=node;
                    pq.push({dis+wt,neighbour});
                }
            }
        }
        
        if(dist[n]==INT_MAX)return {-1};
        
        int node=n;
        vector<int>path;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        
        reverse(path.begin(),path.end());
        return path;
        
    }
};

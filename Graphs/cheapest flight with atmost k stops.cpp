class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        //getting the graph ready
        vector<pair<int,int>> adj[n];
        for(auto i : flights){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adj[u].push_back({v,wt});
        }
        
        //{stops,{node,dist}}
        queue<pair<int,pair<int,int>>>q;//pq is not used as stops are in increasing manner
        q.push({0,{src,0}});
        
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            for(auto i : adj[node]){
                int neighbour=i.first;
                int ewt=i.second;
                if(dis + ewt < dist[neighbour] and stops<=K){
                    dist[neighbour]=dis+ewt;
                    q.push({stops+1,{neighbour,dist[neighbour]}});
                }
            }
        }
        
        if(dist[dst]==1e9)return -1;
        
        return dist[dst];
        
    }
};

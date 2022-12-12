vector<int> bellman_ford(int v, vector<vector<int>>& edges, int S) {
        vector<int>dist(v,1e8);
        dist[S]=0;
        for(int i=0;i<v-1;i++){
            for(auto i : edges){
                int u=i[0];
                int v=i[1];
                int wt=i[2];
                if(dist[u]!=1e8 and dist[v] > dist[u] + wt){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        //do one more to find negative cycle
        for(auto i : edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dist[u]!=1e8 and dist[v] > dist[u] + wt){
                return {-1};
            }
        }
        
        return dist;
    }

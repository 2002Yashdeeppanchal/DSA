vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,s});
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int neighbour=it[0];
                int wt=it[1];
                if(d + wt < dist[neighbour]){
                    dist[neighbour]=d+wt;
                    pq.push({d+wt,neighbour});
                }
            }
        }
        return dist;
    }

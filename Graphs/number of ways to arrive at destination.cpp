class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>>adj[n];
        for(auto i : roads){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        
        vector<int>ways(n,0);
        ways[0]=1;
        vector<int>dist(n,1e9);
        dist[0]=0;
        int mod=(int)(1e9 +7);
        
        while(!q.empty()){
            int node=q.top().second;
            int dis=q.top().first;
            q.pop();
            for(auto i : adj[node]){
                int neighbour=i.first;
                int wt=i.second;
              //this is the first time we are on this node 
                if(dis + wt < dist[neighbour]){
                    dist[neighbour]=dis+wt;
                    ways[neighbour]=ways[node];
                    q.push({dis+wt,neighbour});
                }
              //another time visit on that node
                else if(dis+wt==dist[neighbour]){
                    ways[neighbour]=(ways[neighbour]+ways[node])%mod;
                }
            }
        }
        
        
        return ways[n-1]%mod;
        
    }
};

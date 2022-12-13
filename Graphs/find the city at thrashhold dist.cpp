using floyd warshall algorithm

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int thrashhold) {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto i : edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        //shortest dist matrix bna li flyod ka use krke
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]==INT_MAX or dist[via][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        
        int under_the_th_cities=n;
        int cityno=-1;
        
        //ab bs check kro ko 
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dist[city][adjcity] <= thrashhold){
                    cnt++;
                }
            }
            if(cnt <=under_the_th_cities){
                under_the_th_cities=cnt;
                cityno=city;
            }
        }
        
        
        return cityno; 
        
    }
};

using dijkstra


class Solution {
    private:
    void dj(int src,vector<pair<int,int>>adj[],vector<vector<int>> &dist,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq){
        pq.push({0,src});
        dist[src][src]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto i : adj[node]){
                int neighbour=i.first;
                int wt=i.second;
                if(dist[src][neighbour] > dis+wt){
                    dist[src][neighbour]=dis+wt;
                    pq.push({dis+wt,neighbour});
                }
            }
        }
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int thrashhold) {
        
        vector<pair<int,int>>adj[n];
        for(auto i : edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;i++){
            dj(i,adj,dist,pq);
        }
        
        
        int under_the_th_cities=n;
        int cityno=-1;
        
        //ab bs check kro ko 
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dist[city][adjcity] <= thrashhold){
                    cnt++;
                }
            }
            if(cnt <=under_the_th_cities){
                under_the_th_cities=cnt;
                cityno=city;
            }
        }
        
        
        return cityno; 
        
        
    }
};

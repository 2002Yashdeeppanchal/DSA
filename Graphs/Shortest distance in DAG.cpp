class Solution {
    private:
    void toposort(int node,int vis[],vector<pair<int,int>> adj[],stack<int> &st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                toposort(it.first,vis,adj,st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        //get the graph ready
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //do toposort for all component
        int vis[n]={0};
        stack<int>st;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(i,vis,adj,st);//tc - O(v+e)
            }
        }
        
        //do the distance relaxing stuffs
        vector<int> dist(n,1e9);
        dist[0]=0;
        //tc - O(v+e)
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it : adj[node]){
                int wt=it.second;
                int v=it.first;
                if(dist[node]+wt < dist[v]){
                    dist[v]=dist[node]+wt;//dist[node] is the shortest dist to reach 
                    //at node after that we go to 'it'(neighbour)
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
        
    }
};

vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        set<pair<int,int>>st;
        st.insert({0,s});
        
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        
        while(!st.empty()){
            auto i=*(st.begin());
            int node=i.second;
            int dis=i.first;
            st.erase(st.begin());
            for(auto it : adj[node]){
                int neighbour=it[0];
                int wt=it[1];
                if(dis+wt<dist[neighbour]){
                    if(dist[neighbour]!=INT_MAX){
                        st.erase({dist[neighbour],neighbour});
                    }
                    dist[neighbour]=dis+wt;
                    st.insert({dist[neighbour],neighbour});
                }
            }
        }
        
        return dist;
        
    }
